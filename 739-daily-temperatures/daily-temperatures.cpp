class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //when asked about next higher or greater Start from last index first
        int  n = temperatures.size();
        vector<int> ans(n);
        stack<int> st; //used to store idx of elements (to be placed in monotonic order)  
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() and temperatures[st.top()] <= temperatures[i])
            {
                st.pop();
            }

            if(st.empty()) ans[i] = 0;  // whenever you are initialising values to index of a vector
                                        // always make sure that you first declare its size first otherwise Runtime Error will occur
            else ans[i] = st.top() - i;
            st.push(i);
        }
        return ans; 
    }
};