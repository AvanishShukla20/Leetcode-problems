class Solution {
public:
    int isBouquePossible(vector<int>& vec, int day, int k)
    {
        int bqCount = 0,consecutivePairs = 0;
        for(int i = 0; i < vec.size(); i++)
        {
            if(vec[i] <= day) consecutivePairs++;
            else consecutivePairs = 0;
            if(consecutivePairs == k)
            {
                bqCount++;
                consecutivePairs = 0;
            }
        }
        return bqCount; 
    } 
    int minDays(vector<int>& bloomDay, int m, int k) {
        int cnt = 0, i, temp, n = bloomDay.size(), ans;
        if(n < (long)m*k) return -1;
        int D = *max_element(bloomDay.begin(), bloomDay.end());
        int low = 1, high = D;
        int mid;

        while(low <= high)
        {
            mid = low + (high -low) /2 ;
            if(isBouquePossible(bloomDay, mid, k) < m) low = mid + 1;
            else high = mid - 1;      
        }

        return low;
    }
};