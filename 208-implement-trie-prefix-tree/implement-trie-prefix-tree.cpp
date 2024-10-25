class Trie {
public:
    struct trieNode
    {
        bool isEnd;
        trieNode* children[26];
    };

    trieNode* getNode()
    {
        trieNode* t = new trieNode();
        t->isEnd = false;
        for(int i=0; i<26; i++) t->children[i] = NULL;
        return t;
    }

    trieNode* root;
    
    Trie() {
        root = getNode(); //initialised root
    }
    
    void insert(string word) {
        trieNode* temp = root;
        for(int i=0; i<word.size(); i++)
        {
            int charidx = word[i] - 'a';
            if(temp->children[charidx] == NULL)
            {
                trieNode* newchild = getNode();
                temp->children[charidx] = newchild;
            }
            temp = temp->children[charidx];
        }
        temp->isEnd = true;
    }
    
    bool search(string word) {
        trieNode* temp = root;
        for(int i=0; i<word.size(); i++)
        {
            int charidx = word[i] - 'a';
            if(temp->children[charidx] == NULL)
            {
                return false;
            }
            temp = temp->children[charidx];
        }
        if(temp->isEnd == true) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* temp = root;
        for(int i=0; i<prefix.size(); i++)
        {
            int charidx = prefix[i] - 'a';
            if(temp->children[charidx] == NULL)
            {
                return false;
            }
            temp = temp->children[charidx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */