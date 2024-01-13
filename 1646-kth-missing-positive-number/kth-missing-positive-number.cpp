class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        //nice O(n) approach
        for(int i=0; i< arr.size(); i++)
        {
            //increment k whenever you find a number less than k as array element
            if(arr[i] <= k) k++;
            else break;
        }

        return k;

    }
};