class Solution {
public:
    void solve(int n, string& s, vector<string>& store)
    {
        if(s.size() == n)
        {
            store.push_back(s);
            return;
        }
        string temp  = s;
        char ch = s.back();
        if(ch != 'a')
        {
            s += 'a';
            solve(n, s, store);
            s = temp;
        }
        if(ch != 'b')
        {
            s += 'b';
            solve(n, s, store);
            s = temp;
        }
        if(ch != 'c')
        {
            s += 'c';
            solve(n, s, store);
            s = temp;
        }
    }
    string getHappyString(int n, int k) {
        vector<string> store;
        string s = "";
        string t = s + 'a';
        solve(n, t, store);
        t = s + 'b';
        solve(n, t, store);
        t = s + 'c';
        solve(n, t, store);

        // for(int i=0; i<store.size(); i++)
        // {
        //     cout<<store[i]<<" ";
        // }
        if(k > store.size()) return "";

        return store[k-1];
    }
};