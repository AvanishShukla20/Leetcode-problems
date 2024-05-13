class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<vector<int>> v(k);

        int t = 0;

        for(int i=0; i<n; i++)
        {
            v[t].push_back(energy[i]);
            t++;
            if(t == k) t = 0;
        }
        //above creation of data structure took TC - O(n)

        
        int ans = INT_MIN;

        for(auto c : v)
        {
            int suffixSum = 0 ;// i.e prefix sum concept From Behind
            for(int idx =  c.size() - 1; idx >= 0; idx--)
            {
                suffixSum += c[idx];
                ans = max(suffixSum, ans);
            }
            
        }

        //This Above for inside for loop has TC-> O(k*n/k) = O(n)

        return ans;
    }
};