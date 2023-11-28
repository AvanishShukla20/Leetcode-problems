class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        //perfect beautiful solution in my opinion

        int i=0;
        for(int curr : nums )
        {
            //if curr is non zero then we are plaing it at its correct
            //relative position in vector using i

            if(curr != 0)
            {
                nums[i]=curr;
                i++;
            }
        }

        //once relative positioinng of all non zero done 
        //initialising rest with 0

        while(i<nums.size())
        {
            nums[i]=0;
            i++;
        }
    }
};