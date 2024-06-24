class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0, j = 0, n = customers.size(), unsatisfied_cstmers = 0, max_unsatisfied_cstmers = INT_MIN, satisfied = 0;

        for(; j < minutes; j++)
        {
            if(grumpy[j] == 0) satisfied += customers[j];
            else unsatisfied_cstmers += customers[j];
        }

        max_unsatisfied_cstmers = max(max_unsatisfied_cstmers, unsatisfied_cstmers);

        while(j < n)
        {
            if(grumpy[i] == 1) unsatisfied_cstmers -=  customers[i];

            if(grumpy[j] == 1) unsatisfied_cstmers  += customers[j];
            else satisfied += customers[j];

            max_unsatisfied_cstmers = max(max_unsatisfied_cstmers, unsatisfied_cstmers);

            i++;
            j++;
        }


        int result = satisfied + max_unsatisfied_cstmers;
        return result;


    }
};