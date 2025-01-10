struct trieNode{
    trieNode* children[26];
    bool isEndOfWord;
};
class Solution {
public:
    trieNode* getTrieNode()
    {
        trieNode* node = new trieNode();
        for(int i=0; i<26; i++) node->children[i] = NULL;
        node->isEndOfWord = false;
        return node;
    }

    bool insert(trieNode* root,string& word)
    {
        int cnt = 1;
        trieNode* temp = root;
        bool isnew = 0;

        int n= word.size();
        for(int i=0; i<n; i++)
        {
            cout<<word[i]<<" ";
            if(temp->children[word[i]-'A'] == NULL)
            {
                isnew = 1;
                temp->children[word[i]-'A'] = getTrieNode();
            }
            temp = temp->children[word[i]-'A'];
        }

        bool ispref = true;

        if(temp->isEndOfWord == true) ispref = false;

        if(isnew == 0 && ispref == false)
        {
            cout<<"valid one :"<<word<<endl;
            cnt += 1;
        }

        temp->isEndOfWord = true;
        if(cnt == 2) return true;
        return false;
    }    
    vector<string> findRepeatedDnaSequences(string s) {
        trieNode* root = getTrieNode();
        unordered_set<string> st;
        
        int n=s.size();
        if(n <= 10) return {};

        string start = s.substr(0, 10);
        int j=10;
        insert(root, start);
        for(; j<n; j++)
        {
            start.erase(0, 1);
            start += s[j];
            cout<<start<<endl;
            bool x = insert(root, start);
            if(x == true) st.insert(start);
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};