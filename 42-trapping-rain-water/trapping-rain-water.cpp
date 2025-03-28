class Solution {
public:
    int trap(vector<int>& height) {
        // for calculating amount of water on ith building roof -> 
        /* you need to have value of highest bulding on left side and highest building on right size from  with height > current building */

        int n=height.size();
        vector<int> highestOnleft(n);
        vector<int> highestOnRight(n);

        highestOnleft[0] = height[0];
        highestOnRight[n-1] = height[n-1];
        
        for(int i=1; i<n; i++)
        {
            highestOnleft[i] = max(highestOnleft[i-1], height[i]);
        }

        
        for(int i=n-2; i>=0; i--)
        {
            highestOnRight[i] = max(highestOnRight[i+1], height[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            ans += min(highestOnleft[i] - height[i], highestOnRight[i] - height[i]);
        }

        return ans;
    }
};