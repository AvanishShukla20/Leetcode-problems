class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        int totalSum = 0;
        vector<int> freq(1001, 0);

        for(int i=0; i<n; i++)
        {
            freq[skill[i]]++;
            totalSum += skill[i];
        }
        if(totalSum % (n/2) != 0) return -1;

        int targetSum = totalSum/(n/2);
        long long sum = 0;
        int noOfPair = 0;
        

        for(int currskill : skill) // i am iterating in skill array not in freq array
        {
            int partner = targetSum - currskill;
            if(freq[partner] == 0) return -1;

            sum += 1LL * currskill * partner;
            freq[partner]--;
        }

        return sum/2;
    }
};