class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> ansSet;


        for(int i = 0; i<n; i++)
        {

            //using two pointers and total sum algorithm to get sum = 0
            int j = i+1;
            int k = n-1; // the two pointers we will be using are (j, k)

            while(j<n && j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];

                if(sum > 0)
                {
                    k--;
                }
                else if(sum < 0) j++;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                    k--;
                    j++;
                }
            }
            
        }

        for(auto &it : ansSet) ans.push_back(it);
        return ans;
    }
};