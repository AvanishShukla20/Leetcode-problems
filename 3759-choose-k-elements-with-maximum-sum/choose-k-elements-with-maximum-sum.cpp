class Solution {
public:
    typedef long long ll;
    
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<ll> ans(n, 0);
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++)
        {
            vec.push_back({nums1[i], i});
        }

        unordered_map<int, ll> mpp;

        sort(vec.begin(), vec.end());
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        ll sum = 0;

        int j = 0; // this will be used to track valid elements
        for(int i = 0; i<n; i++)
        {
            int idx = vec[i].second;

            // i am using while(j < i) instead of each time incrementing ...so as to handle duplicate wala case
            while(j <= i)
            {
                if(vec[j].first == vec[i].first) break;
                
                int m = vec[j].second; // original idx of previous -> used to get nums2 ki value at jth idx

                sum += nums2[m];
                pq.push(nums2[m]);

                if(pq.size() > k)
                {
                    auto c = pq.top();
                    pq.pop();
                    sum -= c;
                }
                j++;
            }
            mpp[idx] = sum;
        }

        for (int i = 0; i < n; i++)
            ans[i] = mpp[i];

        return ans;
    }
};