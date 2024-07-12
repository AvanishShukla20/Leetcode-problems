class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        queue<int> idxStore;
        int l = 0, r = 0, maxlen = 0, n = nums.size(), idx = -1;

        while(r < n)
        {
            if(nums[r] == 0)
            {
                idxStore.push(r);
                if(idxStore.size() > k)
                {
                    idx = idxStore.front();
                    idxStore.pop();
                    l = idx + 1;
                }

                maxlen = max(maxlen, r - l + 1);
            }
            else
            {
                maxlen = max(maxlen, r- l + 1);
            }
            r++;
        }

        return maxlen;
    }
};