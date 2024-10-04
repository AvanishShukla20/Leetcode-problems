class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());
        int i = 0, j = n-1;
        int sum = skill[0] + skill[n-1];
        long long ans = 0;

        while(i < j)
        {
            if(skill[i] + skill[j] == sum)
            {
                ans = ans + (1LL * skill[i] * skill[j]);
            }
            else return -1;
            i++;
            j--;
        }

        return ans;
    }
};