class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        vector<int> vec;
        int ans = 0, n = nums.size();
        for(int i=0; i<n; i++)
        {
            int cnt = 0;
            for(int j = i; j<n; j++)
            {
                vec.push_back(nums[j]);
                if(nums[j]%p == 0)
                {
                    cnt++;
                }
                if(cnt > k) break;

                if(st.find(vec) == st.end()) 
                {
                    ans++;
                    st.insert(vec);
                }
            }
            vec.clear();
        }

        return ans;
    }
};