#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;   
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> myset; 

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {  
        int n = nums.size();
        vector<int> arr1, arr2;
        myset s1, s2;
        arr1.push_back(nums[0]);
        s1.insert({nums[0], 0});
        arr2.push_back(nums[1]);
        s2.insert({nums[1], 1});

        for(int i = 2; i< n; i++)
        {
            int search_val = nums[i] + 1;
            int ind1 = s1.order_of_key({search_val, -1}); // added -1 so as deal duplicates
            int ind2 = s2.order_of_key({search_val, -1});
            int grcnt1 = arr1.size() - ind1;
            int grcnt2 = arr2.size() - ind2;

            if(grcnt1 > grcnt2)
            {
                arr1.push_back(nums[i]);
                s1.insert({nums[i], i});
            }
            else if(grcnt1 < grcnt2)
            {
                arr2.push_back(nums[i]);
                s2.insert({nums[i], i});
            }
            else if(grcnt1 == grcnt2)
            {
                if(arr1.size() <= arr2.size())
                {
                    arr1.push_back(nums[i]);
                    s1.insert({nums[i], i});
                }
                else
                {
                    arr2.push_back(nums[i]);
                    s2.insert({nums[i], i});
                }
            }
        }


        vector<int> ans;
        for(auto x:arr1) ans.push_back(x);
        for(auto x:arr2) ans.push_back(x);
        
        return ans;
    }
};