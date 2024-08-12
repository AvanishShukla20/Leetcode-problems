class KthLargest {
public:
    int p;
    vector<int> stream;
    //min-heap taken because it is asked about largest... :)
    priority_queue<int, vector<int>, greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        p = k;
        for(auto &it : nums)
        {
            pq.push(it);
            stream.push_back(it);
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > p)
        {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */