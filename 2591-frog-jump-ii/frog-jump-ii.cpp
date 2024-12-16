class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n=stones.size();
        if(n <= 2) return stones[n-1]; 
        int ans = 0;
        for(int i =0; i<n-2; i++)
        {
            ans = max(ans, stones[i+2] - stones[i]);
        }
        return ans;
    }
};