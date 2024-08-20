class Solution {
public:
    int solve(int k)
    {
        priority_queue<long long , vector<long long>, greater<long long>> pq;
        pq.push(1);
        long long cnt = 0, ans = 0;
        while(!pq.empty() && cnt < k)
        {
            long long num = pq.top();
            pq.pop();
            if(ans == num) continue;
            ans = num;
            cnt++;
            pq.push(num*2);
            pq.push(num*3);
            pq.push(num*5);
        }

        return ans;
    }
    int nthUglyNumber(int n) {
        return solve(n);
    }
};