class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n =nums.size();
        int greaterPos = 0;

        // finding pos for first greater element
        for(int i=0; i<n; i++)
        {
            if(nums[i] <= pivot) greaterPos++;
        }

        int lessPos = 0;   
        //equal will have its position just before the greater one
        int equalPos = greaterPos - 1;


        vector<int> ans(n);

        for(int j =0; j< n; j++)
        {
            if(nums[j] < pivot)
            {
                ans[lessPos] = nums[j];
                lessPos++;
            }
            else if(nums[j] > pivot)
            {
                ans[greaterPos] = nums[j];
                greaterPos++;
            }
            else
            {
                //for equal to pivot
                ans[equalPos] = nums[j];
                equalPos--;
            }
        }

        
        return ans; 
    }
};