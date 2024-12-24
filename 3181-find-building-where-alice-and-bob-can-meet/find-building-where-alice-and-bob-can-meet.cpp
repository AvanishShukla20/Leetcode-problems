class Solution {
public:
    vector<int> segmentTree;
    void buildSegTree(vector<int>& heights, int start, int end, int node_idx)
    {
        // start and end are the start and end of range this node will represent
        if(start == end)
        {
            segmentTree[node_idx] = start;
            return;
        }

        int mid = start + (end-start)/2;
        int leftChildIdx = 2*node_idx;
        int rightChildIdx = 2*node_idx + 1;
        buildSegTree(heights, start, mid, leftChildIdx);
        buildSegTree(heights, mid+1, end, rightChildIdx);

        segmentTree[node_idx] = heights[segmentTree[leftChildIdx]] >= heights[segmentTree[rightChildIdx]] ? segmentTree[leftChildIdx] : segmentTree[rightChildIdx];

    }

    int rangeMaxQuery(vector<int>& heights, int reqs, int reqe, int start, int end, int node_idx)
    {
        if(reqs <= start && end <= reqe) // total overlap start and end are of given node
        {
            return segmentTree[node_idx];
        }
        if(reqe < start || end < reqs)
        {
            return INT_MIN;
        }

        int mid = start + (end-start)/2;
        int leftChildIdx = 2*node_idx;
        int rightChildIdx = 2*node_idx + 1;

        int left = rangeMaxQuery(heights, reqs, reqe, start, mid, leftChildIdx);
        int right = rangeMaxQuery(heights, reqs, reqe, mid+1, end, rightChildIdx);

        if(left == INT_MIN) return right;
        if(right == INT_MIN) return left;

        return heights[left] >= heights[right] ? left : right;
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segmentTree = vector<int> (4*n + 1);
        int node_idx = 1;


        buildSegTree(heights, 0, n-1, node_idx);

        vector<int> result;

        for(auto &query : queries)
        {
            int aliceidx = min(query[0], query[1]);
            int bobidx = max(query[0], query[1]);

            if(aliceidx == bobidx || heights[aliceidx] < heights[bobidx])
            {
                result.push_back(bobidx);
                continue;
            }

            // perform binary search and RMQ using segment tree for Next greater element

            int low = bobidx;
            int high = n-1;
            int ans = INT_MAX;
            while(low <= high)
            {
                int mid = low + (high-low)/2;
                int rmq = rangeMaxQuery(heights, low, mid, 0, n-1, node_idx);

                if(heights[rmq] > heights[aliceidx])
                {
                    ans = min(ans, rmq);
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }

            }
            if(ans == INT_MAX) result.push_back(-1);
            else result.push_back(ans);
            
        }
        
        return result;
        
    }
};