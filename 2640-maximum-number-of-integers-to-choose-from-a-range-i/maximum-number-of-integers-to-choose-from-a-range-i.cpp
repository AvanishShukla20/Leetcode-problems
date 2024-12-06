class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<int> vec;
        unordered_set<int> st(banned.begin(), banned.end());

        for(int i = 1; i<= n; i++)
        {
            if(i <=n && st.find(i) == st.end()) vec.push_back(i);
        }
        int cnt = 0, sum = 0, check = 0;
        sort(vec.begin(), vec.end());

        for(int i = 0; i<vec.size(); i++)
        {
            check += vec[i];
        }

        if(check <= maxSum) return vec.size();

        for(int i =0; i<= vec.size(); i++)
        {
            sum += vec[i];
            if(sum <= maxSum) cnt++;
            else break;
        }
        return cnt;

    }
    
    
};