struct trieNode{
    int cnt =0;
    trieNode* children[26];
    // note in this implementation we do not need isEndOfWord So, we neglect it
};

class Solution {
public:
    trieNode* getTrieNode()
    {
        trieNode* node = new trieNode();
        for(int i=0; i<26; i++) node->children[i] = NULL;
        node->cnt = 0;
        return node;
    }

    void insert(string& s, trieNode* root)
    {
        trieNode* curr = root;
        for(auto &ch : s)
        {
            if(curr->children[ch-'a'] == NULL)
            {
                curr->children[ch-'a'] = getTrieNode(); 
            }
            // wrong thing you were doing -> curr->cnt++
            //correct->
            curr->children[ch-'a']->cnt += 1;
            curr = curr->children[ch-'a'];
        }
    }
    int cntPrefixes(string&s, trieNode* root)
    {
        trieNode* temp = root;
        int ans =0;
        for(int i=0;i<s.size();i++)
        {
            char ch = s[i];
            if(root->children[ch-'a'] != NULL)
            {
                ans += root->children[ch-'a']->cnt;
                root = root->children[ch-'a'];
            }
        }
        return ans;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        trieNode* root = getTrieNode();
        vector<int> vec(n, 0);
        for(auto &str : words)
        {
            insert(str, root);
        }

        int ans = 0;

        for(int i=0; i<n; i++)
        {
            ans = cntPrefixes(words[i], root);
            vec[i] = ans;
        }

        return vec;
    }
};