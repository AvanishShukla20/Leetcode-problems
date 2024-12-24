class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int prefixCount; // Tracks the number of words sharing this prefix
    TrieNode() {
        prefixCount = 0;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert function to build the Trie and track prefix counts
    void insert(const string& word) {
        TrieNode* current = root;
        for (const char& ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                current->children[ch] = new TrieNode();
            }
            current = current->children[ch];
            current->prefixCount++;
        }
    }

    // Calculate the prefix score for a given word
    int getPrefixScore(const string& word) {
        TrieNode* current = root;
        int score = 0;
        for (const char& ch : word) {
            if (current->children.find(ch) == current->children.end()) {
                break;
            }
            current = current->children[ch];
            score += current->prefixCount;
        }
        return score;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        // Build the Trie with all the words
        for (const string& word : words) {
            trie.insert(word);
        }

        // Calculate the prefix scores for each word
        vector<int> result;
        for (const string& word : words) {
            result.push_back(trie.getPrefixScore(word));
        }

        return result;
    }
};
