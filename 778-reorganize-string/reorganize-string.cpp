class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        int n = s.size();
        unordered_map<char, int> mpp;
        
        for(int i=0; i<n; i++)
        {
            mpp[s[i]]++;
            if(mpp[s[i]] > (n+1)/2 ) 
            {
                return "";
            }
        }

        priority_queue<pair<int,char> > pq; // To automatically sort the updated freq 

        for(auto x : mpp)
        {
            pq.push({x.second, x.first});
        }

        char ch1,ch2 ;
        int temp1 = 0, temp2 = 0;

        while(pq.size() >= 2)
        {
            //ek baar me do leke jaana hai -> learnt by testcase "vvvlo"
            ch1 = pq.top().second;
            temp1 = pq.top().first;
            pq.pop();


            ch2 = pq.top().second;
            temp2 = pq.top().first;
            pq.pop();
            
            ans += ch1;
            ans += ch2;

            if(temp1 > 1)
            {
                temp1--;
                pq.push({temp1, ch1});
            }
            if(temp2 > 1)
            {
                temp2--;
                pq.push({temp2, ch2});
            }
                 
        }

        if(pq.size() == 1)
        {
            ans += pq.top().second;
        }

        return ans;
    }
};