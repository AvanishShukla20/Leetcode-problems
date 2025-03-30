class Solution {
public:
    typedef pair<int, string> P;

    struct compHeap{
        bool operator()(P& a, P& b)
        {
            string as = a.second, bs = b.second;
            return a.first > b.first || (a.first == b.first && as < bs);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size(), cnt =0;
        unordered_map<string, int> mpp;

        for(auto it: words) mpp[it]++;

        

        // building a comparator kind of thing for heap :O
        priority_queue<P, vector<P>, compHeap> pq;
        
        //
        for(auto l : mpp)
        {
            pq.push({l.second, l.first});
            if(pq.size() > k) pq.pop();
        }

        vector<string> ans;
        while(!pq.empty())
        {
            cout<<pq.top().second<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};