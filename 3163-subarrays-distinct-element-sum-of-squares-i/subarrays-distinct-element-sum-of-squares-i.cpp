class Solution {
public:
    int sumCounts(vector<int>& nums) {
      if(nums.size()==1) return 1;
      else
      {
          int res=0;
          for(int i=0; i < nums.size(); i++)
          {
              unordered_set<int> s;
              for(int j=i; j<nums.size(); j++)
              {
                  s.insert(nums[j]);
                  res += s.size() * s.size();
              }
              
          }
          return res;
      }  
    }
};