class Solution {
public:
    bool hasMatch(string s, string p) {
        int n= s.size(), m=p.size();
        bool ans = false;
        int starmark = -1;
        for(int i=0; i<m;i++)
        {
            if(p[i] == '*')
            {
                starmark = i;
                break;
            }
        }

        string pref = p.substr(0, starmark);
        string suff = p.substr(starmark+1);
        cout<<" p : "<<pref<<" s : "<<suff<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=i;j<n;j++)
            {
                string str = s.substr(i, j-i+1);
                cout<<str<<endl;
                string part1 = str.substr(0, pref.size());
                cout<<" part1 :"<<part1<<" ";

                if(part1 == pref)
                {
                    cout<<"part1 match now part 2 check : "<<endl;
                    if(suff.empty()) return true;
                    
                    int k=pref.size();

                    while(k < str.size())
                    {
                        string checker = str.substr(k, suff.size());
                        cout<<"checcker : "<<checker<<" ";
                        if(checker == suff) return true;
                        k++;
                    }
                    cout<<endl;
                }
                
            }
        }

        return ans;

    }
};