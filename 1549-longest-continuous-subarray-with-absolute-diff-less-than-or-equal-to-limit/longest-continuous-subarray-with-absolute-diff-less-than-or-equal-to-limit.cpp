class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        priority_queue<pair<int,int>> maxheap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > minheap;


        int i = 0, j = 0, n =  nums.size(), ans = INT_MIN,sublen;

        while(i < n)
        {

            minheap.push({nums[i], i});
            maxheap.push({nums[i], i});

            while(maxheap.top().first - minheap.top().first > limit)
            {

                int idxToRemove = min(maxheap.top().second, minheap.top().second);

                j = idxToRemove + 1;

                while(minheap.top().second < j)
                {
                    minheap.pop();
                }
                while(maxheap.top().second < j)
                {
                    maxheap.pop();
                }
            }

            sublen = i - j + 1;
            ans = max(ans, sublen);
            i++;
            
        }

        return ans;
    }
};