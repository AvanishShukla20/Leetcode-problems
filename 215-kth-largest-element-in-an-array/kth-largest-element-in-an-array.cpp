class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       //simply using priority queue
        priority_queue < int > pq;
        for(int i=0; i< nums.size(); i++)
        {
            pq.push(nums[i]);
        }

        for(int j=1; j<k; j++)
        {
            pq.pop();
        }
        return pq.top();
    }
};