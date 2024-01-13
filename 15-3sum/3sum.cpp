class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
       sort(nums.begin(), nums.end());
       set<vector<int>> s;
       int n = nums.size();
       for(int i=0; i<n ; i++)
       {
           int j=i+1, k= n-1;
           while(j < k)
           {
               int sum = nums[i]+nums[j]+nums[k];
               if(sum > 0)
               {
                   k--; //bring down k by one step
               }
               else if(sum < 0)
               {
                   j++; //bring up j by one step
               }
               else
               {
                   //Case when sum == 0 found
                   s.insert({nums[i], nums[j], nums[k]});
                   j++; 
                   k--;
                   
               } 
           }
       } 

        for(auto triplet : s)
        {
            ans.push_back(triplet);
        }
       return ans;
    }
};

