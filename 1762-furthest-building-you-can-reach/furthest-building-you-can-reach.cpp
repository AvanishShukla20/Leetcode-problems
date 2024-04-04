class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;

        int jump;
        int ans = 0;

        for(int i =0; i< heights.size() - 1; i++)
        {
            jump = heights[i+1] - heights[i];
            if(jump <= 0) ans++;
            else
            {
                /*  greedily fill queue only upto size of no of ladders */
                pq.push(jump);

                /*  as soon as you get 1st jump that makes (pq.size() > ladders). You handle the min 
                    jump currently heap has with the no of bricks available i.e 
                    subtract the min jump from bricks .if difference less than zero we can,t handle the jumps currently in heap
                    we return here .
                */
                
                if(pq.size() > ladders)
                {
                    bricks -= pq.top();
                    if(bricks < 0) return ans;
                    pq.pop();
                }
                ans++;
            }
        }
        
        return ans;
    }
};