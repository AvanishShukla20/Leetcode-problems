class Solution {
public:
    int binsearch(int val, int l, int h, vector<int>&nums)
    {
        int n = nums.size(), ans = n, mid;
        while(l <= h)
        {
            mid = l + (h-l)/2;
            if(nums[mid]>= val)
            {
                ans = mid;
                h = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();

        int pr = -1,sf = n;
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]<=arr[i+1]) pr = i;
            else break;
        }
        pr++;
        if(pr == n-1) return 0; 

        for(int i=n-1;i>=1;i--)
        {
            if(arr[i-1]<=arr[i])
            {
                sf = i-1;
            }
            else break;
        }
        if(sf == n) sf--;

        cout<<"pr : "<<pr<<"sf : "<<sf<<endl;
        int len = sf;
        for(int k = 0; k<=pr; k++)
        {
            int find_in_suffix = binsearch(arr[k], sf, n-1, arr);
            cout<<find_in_suffix<<" ";
            len = min(len, abs(find_in_suffix - k - 1));
        }

        return len;
    }
};