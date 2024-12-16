class Solution {
public:
    bool check(int& val, int& h, vector<int> piles)
    {
        long long cnt = 0;
        for(int i=0; i<piles.size(); i++)
        {
            cnt += piles[i]/val;
            if(piles[i]% val != 0) cnt += 1;
        }

        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int high = *max_element(piles.begin(), piles.end());
        int low = 1, mid;
        int ans = 0;

        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(check(mid, h, piles))
            {
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        return ans;
    }
};