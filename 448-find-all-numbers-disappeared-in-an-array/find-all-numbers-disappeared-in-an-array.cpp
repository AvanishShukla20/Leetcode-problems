class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
     unordered_set<int> s;
     for(int n : nums)
     {
         s.insert(n);
     }
     vector<int> sol;
     for(int i=1; i<=nums.size(); i++)
     {
         if(s.find(i) == s.end())
         {
             sol.push_back(i);
         }
     }
     return sol;   
    }
};