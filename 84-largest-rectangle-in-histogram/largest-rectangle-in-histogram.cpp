class Solution {
public:
    void populateLeft(vector<int>& heights, unordered_map<int, pair<int, int>>& mpp)
    {
        int n = heights.size();
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i]) // delete if found equal also
            {
                st.pop();  
            }
            if(!st.empty()) mpp[i].first = st.top() + 1;
            else mpp[i].first = 0;// if the stack  became empty it means there is no one on left that is lesser than element at current idx . Hence always put-> 0 in this case
            st.push(i);
        }
    }
    void populateRight(vector<int>& heights, unordered_map<int, pair<int, int>>& mpp)
    {
        int n = heights.size();
        stack<int> st;
        for(int i = n-1; i>= 0; i--)
        {
            int equalidx = i;
            while(!st.empty() && heights[st.top()] >= heights[i]) // delete if found equal also
            {
                st.pop();
            }
            if(!st.empty()) mpp[i].second = st.top() - 1;
            else mpp[i].second = n - 1; // if the stack  became empty it means there is no one on right that is lesser than element aat current idx . Hence always put-> n-1 in this case

            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        unordered_map<int, pair<int, int>> mpp;
        int maxArea = INT_MIN;

        populateLeft(heights, mpp);
        populateRight(heights, mpp);

        int area, width, height;
        for(int i = 0; i<n; i++)
        {
            width = mpp[i].second - mpp[i].first + 1;
            height = heights[i];
            area = width*height;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};