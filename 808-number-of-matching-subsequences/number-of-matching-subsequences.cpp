class Solution {
public:
    int up_bound(vector<int>& nums, int val)
    {
        int ans = -3;
        int low = 0, high = nums.size()-1, mid;
        while(low <= high)
        {
            mid = low+(high-low)/2;
            if(nums[mid] > val)
            {
                ans = nums[mid];
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int> > mpp;
        int n = s.size();
        for(int i=0;i<n; i++)
        {
            mpp[s[i]].push_back(i);
        }

        int ans = 0;
        for(int i=0; i<words.size(); i++)
        {
            string tocheck = words[i];
            int prev_idx = -1;
            bool p = true;
            for(int j = 0; j<tocheck.size(); j++)
            {
                char ch = tocheck[j];
                if(mpp.find(ch) == mpp.end())
                {
                    p = false;
                    break;
                }

                int idxOffer = up_bound(mpp[ch], prev_idx);
                if(idxOffer < prev_idx)
                {
                    p = false;
                    break;
                }
                else prev_idx = idxOffer;
            }
            if(p == true) ans += 1;
        }
        return ans;
    }
};