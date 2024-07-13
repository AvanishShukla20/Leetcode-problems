class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();

        vector<int> vec(n + 1, -1);

        int l = 0, r = 0, cnt = 0, ans = 0;

        while(r < n)
        {
            if(vec[fruits[r]] == -1)
            {
                if(cnt == 2)
                {
                    while(vec[fruits[l]] >= 0)
                    {
                        vec[fruits[l]] -= 1;
                        if(vec[fruits[l]] == -1)
                        {
                            l++;
                            break;
                        }
                        else l++;
                    }
                }
                else cnt++;
            }
            
            vec[fruits[r]] += 1;
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};