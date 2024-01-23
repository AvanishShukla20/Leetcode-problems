class Solution {
public:

    //Memo array as global variable 
    int t[101]; // as 101 is max size of array given in constraints

    int MaxMoney(int idx, vector<int>& nums)
    {
        if(idx >= nums.size())
        {
            return 0;
        }
        //check memo conditions before function calls
         
        if(t[idx] != -1) return t[idx];
        
        int choriKiya = nums[idx] + MaxMoney(idx+2,nums);
        int choriNahiKiya = MaxMoney(idx+1,nums);

        int res = max(choriKiya, choriNahiKiya);

        t[idx] = res;
        return res;

    }
    int rob(vector<int>& nums) {

        //initialise memo array with all values as -1
        memset(t, -1, sizeof(t));
        return MaxMoney(0,nums);
        
       

    }
};