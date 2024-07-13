class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // using map can be a very much better way to implement this ques
        unordered_map<int, int> mpp;
        int l = 0, r = 0, ans = 0, n = fruits.size();

        while(r < n)
        {
            mpp[fruits[r]]++;

            // shrink if size of map is greater than 2

            while(mpp.size() > 2)
            {
                if(mpp[fruits[l]] == 1) mpp.erase(fruits[l]);
                else mpp[fruits[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
            r++;

        }

        return ans;
    }
};