class Solution {
public:
    int mod = 1000000000+7;
    int modpower(int base,int exponent) 
    {
        // helps to get power mulitplication done in log(b) order if a^b is to be calculated 
        long long result = 1;
        base = base%mod;

        while(exponent > 0)
        {
            int lastbit = exponent&1;

            if(lastbit != 0)
            {
                result = (result*base)%mod;
            }
            exponent = exponent>>1;
            base = (1LL*base*base)%mod;
        }
        return result;

    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        int n=nums.size();
        const long maxi = *max_element(nums.begin(), nums.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pair first element = element value , and second value = idx
        for(int i=0; i<n; i++)
        {
            pq.push({nums[i], i});
        }

        // brutely simulate the process until every element gets multiplied by atleast once 
        while(k > 0 && (1LL*multiplier*pq.top().first) <= maxi)
        {
            int val = (multiplier*pq.top().first)%mod;
            int idx = pq.top().second;
            pq.pop();
            pq.push({val, idx});
            k--; 
        }

        // if still k is remaining it means we have to go to our observation part wala whre a pattern is seen repeating after every n sized blocks 

        const long powerNum = modpower(multiplier, k/n); // powerNum is no to be multiplied with nums elements at the very last 

        while(!pq.empty())
        {
            auto mini = pq.top();
            pq.pop();
            int val = mini.first;
            int idx = mini.second;

            if(k%n > 0) // some chunk is left
            {
                nums[idx] = ((1LL*powerNum*multiplier)%mod * val)% mod;
                k--;
            }
            else 
            {
                nums[idx] = (1LL*powerNum*val)%mod;
            }
        }

        return nums;

    }
};