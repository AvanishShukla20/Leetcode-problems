class Solution {
public:
    string solve(string strnum, vector<int>& mapping)
    {
        string ans = "";
        for(int i = 0; i < strnum.size(); i++)
        {
            ans += to_string(mapping[strnum[i] - '0']);
        }
        return ans;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<pair<int, int>> vec;

        for(int i =0; i < nums.size(); i++)
        {  
            string strnum = to_string(nums[i]);

            string mappedstr = solve(strnum, mapping);

            int mappedNum = stoi(mappedstr);

            vec.push_back({mappedNum, i});
        }

        

        sort(vec.begin(), vec.end());
        vector<int> ans;

        for(int i =0; i<vec.size(); i++)
        {
            ans.push_back(nums[vec[i].second]);
        }
        return ans;
    }
};