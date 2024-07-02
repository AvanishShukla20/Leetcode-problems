class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int m =nums1.size(), n = nums2.size(), target;
        if(m < n) target = m;
        else target = n;

        int i = 0, j = 0;
        vector<int> ans;
        if(target == n)
        {
            while(i < m && j < n)
            {
                
                if(nums1[i] >= nums2[j])
                {
                    if(nums1[i] == nums2[j])
                    {
                        ans.push_back(nums1[i]);
                        i++;
                    }
                    j++;
                }
                else i++;
            }
        }
        else
        {
            while(i < n && j < m)
            {
                
                if(nums2[i] >= nums1[j])
                {
                    if(nums2[i] == nums1[j])
                    {
                        ans.push_back(nums2[i]);
                        i++;
                    }
                    j++;
                }
                else i++;
            }
        }
        return ans;
    }
};