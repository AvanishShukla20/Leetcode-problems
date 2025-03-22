class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size(), req = n/3;

        int e1 = 0, cnt1 = 0, e2 = 0, cnt2 = 0;

        for(int i=0; i<n; i++)
        {
            if(cnt1 == 0  && nums[i] != e2)
            {
                cnt1 = 1;
                e1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != e1)
            {
                cnt2 = 1;
                e2 = nums[i];
            }
            else if(e1 ==  nums[i]) cnt1++;
            else if(e2 == nums[i]) cnt2++;
            else
            {
                //competing element arrives
                cnt1--;
                cnt2--;
            }
        }

        //once manually check
        int c1 = 0, c2 = 0;

        for(int i=0; i<n; i++) if(nums[i] == e1) c1++;
        for(int i=0; i<n; i++) if(nums[i] == e2) c2++;

        vector<int> ans;
        if(c1 > req) ans.push_back(e1);
        if(c2 > req && e1 != e2) ans.push_back(e2);
        return ans;
    }
};