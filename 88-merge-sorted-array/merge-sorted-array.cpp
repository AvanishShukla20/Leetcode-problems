class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int zeropos = -1;

        for(int i = nums1.size() - 1; i >= 0; i--)
        {
            if(nums1[i] != 0)
            {
                zeropos = i;
                break;
            }
        }


        for(int j = 0; j<nums2.size(); j++)
        {
            nums1[zeropos + 1] = nums2[j];

            //placing at correct pos
            int i = zeropos + 1;
            while(i > 0)
            {
                if(nums1[i-1] > nums1[i])
                {
                    swap(nums1[i-1], nums1[i]);
                }
                else break;
                i--;
            }

            zeropos += 1;
        }

    }
};