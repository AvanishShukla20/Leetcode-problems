class Solution {
public:
    int findTheWinner(int n, int k) { 
        vector<int> friends(n);
        for(int i=0; i<n; i++) friends[i] = i+1; 

        unordered_set<int> losers;
        int i, j = 0, rem = n - losers.size(), idxToRemove, cnt;

        while(rem > 1)
        {
            i = j;
            cnt = 0;
            while(cnt < k)
            {
                if(losers.find(friends[j]) == losers.end()) cnt++;

                j = (j + 1)%n; 
            }
            idxToRemove = j;
            if(idxToRemove <= 0) idxToRemove = n - idxToRemove - 1;
            else idxToRemove -= 1;
            
            losers.insert(friends[idxToRemove]);
            rem = n - losers.size();
        }

        int ans;

        for(int i =0; i<n; i++)
        {
            if(losers.find(friends[i]) == losers.end())
            {
                ans = friends[i];
            }
        }
        return ans;
    }
};