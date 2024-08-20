class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int, int>>>> pq;
        // each tuple will store {sum, idxFromNums1, idxFromNums2}

        set<pair<int,int>> st;

        vector<vector<int>> ans(k);
        pq.push({nums1[0]+nums2[0], {0,0}});
        st.insert({0,0});
        int i = 0;

        while(!pq.empty() && i < k)
        {
            auto tuple = pq.top();
            pq.pop();

            int sum = tuple.first;
            int i1 = tuple.second.first;
            int i2 = tuple.second.second;

            ans[i] = {nums1[i1], nums2[i2]};
            int sum1 = 1e9, sum2 = 1e9;

            if(i1+1 < n) sum1 = nums1[i1+1] + nums2[i2];
            if(i2+1< m) sum2 = nums1[i1] + nums2[i2+1];


            if(st.find({i1+1, i2}) == st.end())
            {
                pq.push({sum1, {i1+1, i2}});
                st.insert({i1+1, i2});
            }
            if(st.find({i1, i2+1}) == st.end())
            {
                pq.push({sum2, {i1, i2+1}});
                st.insert({i1, i2+1});
            }
            i++;
        }

        return ans;
    }
};