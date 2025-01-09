class Solution {
public:
    int minOperations(vector<int>& nums, int x) { 
        //find the longest subarray with sum == sum(nums)-x
        int sum = 0;
        int n=nums.size();

        for(int i=0; i<n;i++) sum += nums[i];
        int target = sum - x;

        cout<<"target : "<<target<<endl;

        if(target == 0)
        {
            return n;
        }

        int i = 0, j = 0, start = -1, end = n-1;
        int currsum = 0, maxlen = 0;
        while(j<n)
        {
            currsum += nums[j];

            while(i<j && currsum > target)
            {
                currsum -= nums[i];
                i++;
            }

            if(currsum == target)
            {
                if((j-i+1) > maxlen)
                {
                    cout<<"came: "<<endl;
                    maxlen = j-i+1;
                    start = i;
                    end = j;
                }
            }
            j++;
        }
        
        if(start == -1) return -1;

        int ans = start + (n-end-1);

        return ans;

    }
};