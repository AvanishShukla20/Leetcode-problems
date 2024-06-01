class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // the main thing why this problem is termed hard is to recognisse Why to apply BFS

        queue<pair<string, int>> q;
        unordered_set<string> s(wordList.begin(), wordList.end());
        q.push({beginWord, 1});
        s.erase(beginWord);

        while(!q.empty())
        {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i =0; i<word.size(); i++)
            {
                char original = word[i];

                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if(s.find(word) != s.end())
                    {
                        s.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                // word[i] will be equal to z ...so we convert it back to original string
                word[i] = original;
            }
        }

        return 0;

    }
};