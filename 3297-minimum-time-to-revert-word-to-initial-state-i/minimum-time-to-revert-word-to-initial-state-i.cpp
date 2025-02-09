class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.size();
        int ans = 1;
        // since we necessarily have to do one operation

        int i = k;

        while(i < n)
        {
            int Remlen = (n-i);
            string front = word.substr(0, Remlen);
            string back = word.substr(i);
            cout<<front<<" "<<back<<endl;
            if(front == back) break;
            ans++;
            i += k;
        }
        return ans;
    }
};