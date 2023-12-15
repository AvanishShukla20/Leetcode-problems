class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int i=0,j=0;
      
      sort(nums.begin(),nums.end());
      int pdt1 = (nums[0]-1) * (nums[1]-1) ;
      int pdt2 = (nums[nums.size()-1] -1) * (nums[nums.size()-2]-1);
      int pdtres = pdt1 > pdt2 ? pdt1 : pdt2 ;
      return pdtres;

    }
};