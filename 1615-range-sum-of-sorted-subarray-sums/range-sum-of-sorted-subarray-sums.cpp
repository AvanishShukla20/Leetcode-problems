class Solution {
public:
    const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int pfSum = 0;
        vector<int> vec;
        for(int i = 0; i<n; i++)
        {
            pfSum = 0;
            for(int j = i; j < n ; j++)
            {
                pfSum += nums[j] % mod;
                vec.push_back(pfSum);
            }
        }

        sort(vec.begin(), vec.end());
        cout<<vec.size()<<endl;
        int sum = 0;
        for(int i = left - 1; i < right; i++)
        {
            sum =  (sum + vec[i]) % mod;
        }

        return sum;


    }
};