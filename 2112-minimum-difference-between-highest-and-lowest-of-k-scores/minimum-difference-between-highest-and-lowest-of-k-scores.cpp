class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int i=0,j=k-1;
        //To Do the sorting was the all this ques had
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        
        while(j<nums.size())
        {
            int diff=nums[j] - nums[i]; 
            if(diff < res) res=diff;
            i++;
            j++;
        }
        return res;
    }
};