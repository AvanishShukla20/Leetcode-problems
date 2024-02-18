class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue< int, vector<int>, greater<int>> p;
        /*min heap created -> stores in ascending order */

        /*vector<int> is used to support as a container for ease of access priority queue elements
         as priority queue is implemented using binary heap data structure  */

        int ans = 0 , n = heights.size();
        for(int i = 0; i< n- 1 ; i++)
        {
            //at every indx figure out all possible jumps 
            // required to reach here prior to this index
            int gap = heights[i+1] - heights[i];
            if(gap > 0) p.push(gap);
            /* if size of queue becomes greater than ladders it means we have to use bricks for smallest one*/
            if(p.size() > ladders)
            {
                bricks -= p.top();
                p.pop();
            }

            if(bricks < 0) return i; 
        }
        //if pointer reaches the last building idx
        
        return heights.size() - 1;
    }
};