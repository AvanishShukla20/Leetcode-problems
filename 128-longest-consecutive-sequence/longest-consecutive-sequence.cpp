class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        unordered_set<int> st;
        for(int p : nums) st.insert(p);

        int ans = 1, cnt = 1;
        // traverse in set instead of nums
        for(int val : st)
        {
            if(st.find(val-1) == st.end())
            {
                // if previous do not exist that means this definitely can be a start of some sequence
                cnt = 1;
                int next = val+1;
                while(st.find(next) != st.end())
                {
                    cnt++;
                    next++;
                }
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};