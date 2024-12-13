class Solution {
public:
    typedef long long ll;
    #define P pair<int, int>
    long long findScore(vector<int>& nums) {
        ll sum = 0;
        int n = nums.size();
        priority_queue<P, vector<P>, greater<P>> pq;
        unordered_set<int> st;
        for(int i=0;i<n; i++)
        {
            pq.push({nums[i], i});
            st.insert(i);
        }

        while(!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            ll el = it.first;
            int idx = it.second;
            
            if(st.find(idx) == st.end()) continue;
            sum += el;
            st.erase(idx);
            if(idx == 0) st.erase(1);
            else if(idx == n-1) st.erase(n-2);
            else
            {
                st.erase(idx-1);
                st.erase(idx+1);
            }
            
        }
        return sum;
    }
};