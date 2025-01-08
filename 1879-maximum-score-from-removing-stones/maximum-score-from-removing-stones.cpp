class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int ans=0;
        while(1)
        {
            int p1 = pq.top();
            pq.pop();
            int p2 = pq.top();
            pq.pop();
            if(p1 == 0 || p2 == 0) break;
            ans++;
            p1--;
            p2--;
            pq.push(p1);
            pq.push(p2);
        }


        return ans;
    }
};