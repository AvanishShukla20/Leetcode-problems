class Solution {
public:
    int findTheWinner(int n, int k) {
        // Fantastic : Use of Queue to find idxToRemove;
        queue<int> Q;

        for(int i = 1; i <= n; i++) Q.push(i);

        while(Q.size() > 1)
        {
            for(int i = 0; i < k - 1; i++)
            {
                Q.push(Q.front());
                Q.pop();
            }

            // remove the top element 
            Q.pop();
        }

        return Q.front();
    }
};