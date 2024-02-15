class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0,i=0,j=0;
        int ans = INT_MAX;
        while(j < nums.size() || sum >= target)
        {
            while(sum >= target)
            {
                int size = j - i ;
                ans = min(size, ans);
                cout<<"ans :"<<ans<<" ";
                sum -= nums[i];
                cout<<"sum inside :"<<sum<<" ";
                i++;
            }
            if(j < nums.size()){
                sum += nums[j];
                cout<<"sum :"<<sum<<endl;
                j++;
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};