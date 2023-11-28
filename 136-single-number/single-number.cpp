class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second==1) return i.first;
        }
        return -1;

        // int num=nums[0];

        // for(int i=1;i<nums.size();i++)
        // {
        //     num=num^nums[i];
        // }
        // return num;
    }
};