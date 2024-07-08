class Solution {
public:
    int findTheWinner(int n, int k) {
        //chhose some elements in circular list and dlete some then perform same operation on remaining elements in the list unti you got only one person . return info of this person

        vector<int> friends(n);
        for(int i =0; i<n ;i++)
        {
            friends[i] = i + 1;
        }

        int start = 0, friendsRemaining = friends.size(), idxtoremove;

        while(friendsRemaining > 1)
        {
            idxtoremove = (start + k - 1) % friendsRemaining;

            friends.erase(friends.begin() + idxtoremove);

            friendsRemaining = friends.size();

            start = idxtoremove;
        }

        return friends[0];
    }
};