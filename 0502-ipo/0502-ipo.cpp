class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> profCapTuples;

        for(int i=0; i<profits.size();i++)
        {
            profCapTuples.push_back({capital[i], profits[i]});
        }

        sort(profCapTuples.begin(), profCapTuples.end());
        // sorting based on capitals to easily iterate over all required tuples 

        priority_queue<int> profitsStorage;
        int capReq = w;
        int i=0;
        while(k--)
        { 
            while(i < profCapTuples.size() && profCapTuples[i].first <= capReq)
            {
                profitsStorage.push(profCapTuples[i].second);
                i++;
            }
            if(!profitsStorage.empty())
            {
                capReq += profitsStorage.top();
                profitsStorage.pop();
            }
        }
        return capReq;
    }
};