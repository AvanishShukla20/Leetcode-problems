class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        // search for reqRemainder just before the current idx in remaindercnt freq map

        unordered_map<int,int> remainderCnt;
        int n = hours.size(), remainder, remainderRequired;
        long long ans = 0;
        for(int i = 0; i< hours.size(); i++)
        {
            remainder = hours[i] % 24;
            remainderRequired = 24 - remainder;
            if(remainderCnt.find(remainderRequired) != remainderCnt.end()) ans += remainderCnt[remainderRequired];

            if(remainder == 0) remainderCnt[24] += 1;
            else remainderCnt[remainder]++;
        }
        
        return ans;
    }
};