class Solution {
public:
    void fillnsl(vector<int>&res, vector<int>& nsl, vector<int>& nsr)
    {
        int n = res.size();
        stack<int> st;
        st.push(0);

        int i = 0;
        while(i < n)
        {
            if(!st.empty() && res[st.top()] < res[i])
            {
                nsl[i] = st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && res[st.top()] >= res[i])
                {
                    st.pop();
                }
                if(st.empty()) nsl[i] = -1;
                else nsl[i] = st.top();
                st.push(i);
            }
            i++;
        }

        while(!st.empty()) st.pop();
        i = n-1;

        while(i >= 0)
        {
            if(!st.empty() && res[st.top()] < res[i])
            {
                nsr[i] = st.top();
                st.push(i);
            }
            else
            {
                while(!st.empty() && res[st.top()] >= res[i])
                {
                    st.pop();
                }
                if(st.empty()) nsr[i] = n;
                else nsr[i] = st.top();
                st.push(i);
            }
            i--;
        }


    }

    void nsr(vector<int>& res, vector<int>& nsr)
    {
        stack<int> st;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n, 0));

        for(int j=0;j<n; j++) heights[0][j] = matrix[0][j] - '0';

        for(int i = 1; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j] == '1')
                {
                    heights[i][j] = heights[i-1][j] + 1;
                }
                else heights[i][j] = 0;
            }
        }

        vector<int> res;

        int maxarea = 0;
        for(int i=0; i<m; i++)
        {
            res = heights[i];
            vector<int> nsl(n), nsr(n);
            fillnsl(res, nsl, nsr);

            for(int j=0; j<n; j++)
            {
                int width = nsr[j] - nsl[j] - 1;
                int height = res[j];
                maxarea = max(maxarea, height*width);
            }
        }

        return maxarea;

    }
};