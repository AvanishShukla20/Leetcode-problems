class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);

        st.push(prices[n-1]);
        ans[n-1] = prices[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            int curr = prices[i];
            if(st.top() < curr)
            {
                ans[i] = curr - st.top();
                st.push(curr);
            }
            else
            {
                while(!st.empty() and st.top() > curr) st.pop();

                if(st.empty()) ans[i] = prices[i];
                else ans[i] = curr - st.top();
                st.push(curr);
            }
        }

        return ans;
    }
};