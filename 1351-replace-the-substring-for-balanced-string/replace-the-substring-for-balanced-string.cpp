class Solution {
public:
    bool isReqfulfilled(vector<int>& Reqfreq)
    {
        for(int i=0; i<26; i++)
        {
            if(Reqfreq[i] > 0 ) return false;
        }
        return true;
    }
    int balancedString(string s) {
        int n=s.size();
        int req = n/4;

        vector<int> Reqfreq(26, 0);

        for(int i=0; i<n; i++)
        {
            Reqfreq[s[i]-'A']++;
        }
        // my ultimate goal is to get extra freq of every character included in my window

        for(int i=0; i<26;i++)
        {
            Reqfreq[i] = max(0, Reqfreq[i]-req); // getting extra freq of each char in my Reqfreq
        }

        if(isReqfulfilled(Reqfreq) == true) return 0;

        int  start = 0, end = 0, ans = n;

        while(end < n)
        {
            //add this to window and decrement the freq of it from Reqfreq
            Reqfreq[s[end]-'A']--;

            // if window becomes valid i.e freq of all chars <= 0 shrink window to get minimum window length
            while(isReqfulfilled(Reqfreq) == true)
            {
                
                cout<<"came : "<<endl;
                ans = min(ans, end-start+1);
                Reqfreq[s[start]-'A']++;
                start++;
            }

            end++;
        }

        return ans;
    }
};