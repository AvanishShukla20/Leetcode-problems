class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0, n =  arr.size();

        for(int i = 1; i<n; i++)
        {
            int j = i;
            int cnt = 1;
            bool isdecreasingexist = false;
            while(j < n && arr[j-1] < arr[j])
            {
                cnt++;
                j++;
            }

            //decreasing is counted only once increasing is done in continuation i.e ensured by i != j
            while(i != j && j < n && arr[j-1] > arr[j])
            {
                cnt++;
                j++;
                isdecreasingexist = true;
            }

            if(cnt > 2 && isdecreasingexist)
            {
                res = max(res, cnt);
                j--;
            }
            i = j;
            

        }
        return res;
    }
};