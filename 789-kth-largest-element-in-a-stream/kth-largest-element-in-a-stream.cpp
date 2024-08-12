class KthLargest {
public:
    int p;
    vector<int> stream;

    int findpos(int num, vector<int>& stream)
    {
        int n = stream.size();
        int low = 0, high = n - 1, mid;

        while(low <= high)
        {
            mid = low + (high - low)/2;
            if(stream[mid] == num) return mid;
            else if(stream[mid] < num) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }

    KthLargest(int k, vector<int>& nums) {
        p = k;
        for(auto &it : nums) stream.push_back(it);
        sort(stream.begin(), stream.end());
    }
    
    int add(int val) {
        int idx = findpos(val, stream);
        stream.insert(stream.begin() + idx , val);

        return stream[stream.size() - p];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */