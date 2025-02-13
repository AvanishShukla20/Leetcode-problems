class Solution {
public:
    long long validSubstringCount(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        vector<int> currwind(26, 0), reqwind(26, 0);
        
        // you will NEVER TOUCH THE FREQUENCIES IN REQWIND
        for(int i=0; i<m; i++)
        {
            reqwind[word2[i]-'a']++;
        }

        int k =m; // k will keep track of no of character remaining to be met under window
        cout<<k<<endl;

        int i=0, j=0;
        long long ans = 0;
        
        while(j<n)
        {
            char curr = word1[j];

            // curr is required one ->

            if(reqwind[curr-'a'] > 0)
            {
                // curr window doesn't have as muchh frequency of this required char as we need
                if(currwind[curr-'a'] < reqwind[curr-'a'])
                {
                    k--;
                }
            }
            
            currwind[curr-'a']++;

            while(k == 0)
            {
                // as far as wind contains all characters of word2
                ans += (n-j);

                char ch = word1[i];
                currwind[ch-'a']--;
                if(reqwind[ch-'a'] > 0)
                {
                    if(currwind[ch-'a'] < reqwind[ch-'a'])
                    {
                        k++;
                    }
                }
                i++;
            }
            j++;
            
        }

        /*note i am never disturbing the reqwind as it tells me cnt of all required chars of word2 */

        return ans;
    }
};