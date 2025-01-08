class Solution {
public:
    vector<int> nselL(vector<int>& nums)
    {
        int n= nums.size();
        vector<int> nsl(n);
        stack<int> st;
        st.push(0);
        nsl[0] = -1;
        int i=1;
        while(i<n)
        {
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                st.pop();
            }
            nsl[i] = (!st.empty()) ? st.top() : -1;
            st.push(i);
            i++;
        }

        return nsl;
    }



    vector<int> nselR(vector<int>& nums)
    {
        int n= nums.size();
        vector<int> nsl(n);
        stack<int> st;
        st.push(n-1);
        nsl[n-1] = n;
        int i=n-2;
        while(i>=0)
        {
            while(!st.empty() && nums[st.top()] > nums[i])
            {
                st.pop();
            }
            nsl[i] = (!st.empty()) ? st.top() : n;
            st.push(i);
            i--;
        }

        return nsl;
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int  mod = 1000000007;
        vector<int> nsL = nselL(arr);
        vector<int> nsR = nselR(arr);

        for(int i=0; i<n; i++)
        {
            cout<<" -> "<<nsL[i]<<" "<<nsR[i]<<endl;
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            long addl = i-nsL[i];
            long addr =  nsR[i]-i;
            
            long ml = (((addl%mod)*(addr%mod))%mod * (arr[i]%mod))%mod; 
            ans = (ans%mod + ml%mod)%mod;
        }

        return ans;
    }
};