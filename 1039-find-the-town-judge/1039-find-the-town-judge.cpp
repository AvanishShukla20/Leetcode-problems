class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) { 
        if(n == 1) return 1;  
       unordered_map<int, int> incoming, outgoing;

       for(int i=0; i<trust.size(); i++)
       {

        incoming[trust[i][1]]++;
        outgoing[trust[i][0]]++;
       }

       for(auto it : incoming)
       {
        if(it.second == n-1 && outgoing[it.first] == 0)
        {
            return it.first;
        }
       }

       return -1;


    }
};