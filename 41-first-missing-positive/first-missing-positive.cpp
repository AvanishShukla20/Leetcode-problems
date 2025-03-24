class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        
        if(mini > 1) return 1;

        bool isone = false;
        for(int i=0; i<n; i++)
        {
            if(nums[i] == 1)
            {
                isone = true;
                break;
            }
        }

        if(isone == false) return 1;

        unordered_set<long long> st(nums.begin(), nums.end());

        long long ans = LLONG_MAX;

        for(int i=0; i<n; i++)
        {
            long long v = (long long) nums[i]+1;
            if(nums[i] < 0) continue;
            else if(st.find(v) == st.end()) ans = min(ans, v);
        }
        
        long long maxi = *max_element(nums.begin(), nums.end());

        if(ans == LLONG_MAX) ans = maxi + 1;
        return ans;
    }
};