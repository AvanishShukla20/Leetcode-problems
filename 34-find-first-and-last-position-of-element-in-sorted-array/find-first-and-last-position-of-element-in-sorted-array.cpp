class Solution {
public:

    int FirstOccurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int index = -1, s = 0, e = n-1,mid;

        while(s <= e)
        {
            mid = s + (e -s)/2 ;
            if(nums[mid] == target)
            {
                index = mid;
                // look again for further occurrence in left pat of array
                e = mid -1;
            }
            else if (nums[mid] > target)
            {
                e = mid -1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return index;
    }

    int LastOccurrence(vector<int>& nums, int target)
    {
        int n = nums.size();
        int index = -1, s = 0, e = n-1,mid;

        while(s <= e)
        {
            mid = s + (e -s)/2 ;
            if(nums[mid] == target)
            {
                index = mid;
                // look again for further occurrence in left pat of array
                s = mid + 1;
            }
            else if (nums[mid] > target)
            {
                e = mid -1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        //to find occurences we will have to apply binary search two times 
        //first -> to get the leftmost i.e first occurrence

        int left = FirstOccurrence(nums,target);
        int right = LastOccurrence(nums,target);

        return {left,right};
    }
};