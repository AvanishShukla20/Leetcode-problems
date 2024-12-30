class Solution {
public:
    typedef long long ll;
    int gcd(int a, int b)
    {
        if(a == 0) return b;
        return gcd(b%a, a);
    }


    long long numberOfSubsequences(vector<int>& nums) {
        int n=nums.size();
        //make a map storing count of fractions that can be fromed by r and s .NOTE->
        // in map it is always advisable to store the numerator and denominator as pair in key rather than fraction as key
        map<pair<int, int>, ll> mpp;
        int hcf;
        pair<int, int> fractionPair;
        ll ans = 0;
        for(int r=4; r<n; r++)
        {
            for(int s = r+2; s<n; s++)
            {
                hcf = gcd(nums[s], nums[r]);
                fractionPair = {nums[s]/hcf, nums[r]/hcf};
                mpp[fractionPair]++;
            }
        }

        for(int q = 2; q<n;q++)
        {
            for(int p = 0; p<q-1; p++)
            {
                hcf = gcd(nums[p], nums[q]);
                fractionPair = {nums[p]/hcf, nums[q]/hcf};
                ans += mpp[fractionPair];

            }
                // now as i mve my q forward , the mpp should be updated to contain fractions of only r's possible for this new q
            
                int r = q+2;
                for(int s = r+2; s<n; s++)
                {
                    hcf = gcd(nums[s], nums[r]);
                    fractionPair = {nums[s]/hcf, nums[r]/hcf};
                    mpp[fractionPair]--;
                } 
        }

        return ans;
    }
};