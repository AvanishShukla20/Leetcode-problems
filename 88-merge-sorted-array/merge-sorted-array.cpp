class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // consider testcase To bulid solution -> n1 = [1, 2, 4,6, 8, 10, 12, 0, 0, 0, 0] and 
        // n2 => [5, 6,7, 9, 13] and realise -> .........Going backwards is a good option

        // edge case-> n1 = [3, 4, 0] n2 => [1]

        int i=m-1, j=n-1, k=m+n-1;

        while(j >= 0)
        {
            if(i >= 0 && nums1[i] >= nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
            }
            else
            {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

    }
};