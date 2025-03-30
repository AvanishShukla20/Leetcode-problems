class Solution {
public:
    static bool check(string& a, string& b)
    {
        int n=a.size(), m=b.size(), i=0, j=0;
        while(i<n && j<m)
        {
            if(a[i] != b[j])
            {
                if(a[i] < b[j]) return true;
                return false;
            }
            i++;
            j++;
        }

        if(a.size() <= b.size()) return true;
        return false;
    }
    static bool comp(pair<int, string>& p1, pair<int, string>& p2)
    {
        if(p1.first > p2.first) return true;
        if(p1.first == p2.first)
        {
            // check lexicographically
            string a = p1.second, b=p2.second;
            bool x = check(a, b);
            return x;
        }
        return false;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<pair<int, string>> vec;
       
        int n=words.size(), cnt =0;
        unordered_set<string> st;

        for(int i=0; i<n; i++)
        {
            string d = words[i];
            if(st.find(d) != st.end()) continue;

            cnt = 0;
            for(int j=0; j<n; j++)
            {
                if(words[j] == d) cnt++;
            }
            st.insert(d);
            vec.push_back({cnt, d});
        }

        sort(vec.begin(), vec.end(), comp);
        int i=0;
        for(auto l : vec)
        {
            cout<<l.first<<" "<<l.second<<endl;
        }
        vector<string> ans;
        while(k--)
        {
            ans.push_back(vec[i].second);
            i++;
        }

        
        return ans;

    }
};