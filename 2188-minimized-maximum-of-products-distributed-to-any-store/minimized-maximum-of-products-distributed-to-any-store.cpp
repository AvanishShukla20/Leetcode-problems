class Solution {
public:
    int Shops(int& mVal, vector<int>& q)
    {
        int p = 0;
        for(int i=0;i<q.size(); i++)
        {
            p += q[i]/mVal;
            if(q[i]%mVal != 0) p += 1; 
        }
        return p;
    }
    int bSearch(int n, int& maxi, vector<int>& quantities)
    {
        int ans = maxi;
        int low = 1, high = maxi;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            cout<<"mid : "<<mid<<" ";
            int getReqShops = Shops(mid, quantities);
            cout<<" Shops : "<<getReqShops<<endl;
            if(getReqShops <= n)
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            
        }
        return ans;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int maxi = *max_element(quantities.begin(), quantities.end());
        cout<<maxi<<endl;
        return bSearch(n, maxi, quantities);
    }
};