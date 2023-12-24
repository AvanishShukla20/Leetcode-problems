class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        int k=0;
        vector< int > nums;
        vector< int > res;
        for(int i=0; i< words.size(); i++)
        {
            if(words[i] != "prev")
            {
                k=0;
                nums.push_back(stoi(words[i]));
            }
            else
            {
                k++;
                // rbegin() and rend() are used to initialise  elements of one vector to otherin reverse order
                vector< int > revNum(nums.rbegin(),nums.rend());
                if(k > revNum.size()) res.push_back(-1);
                else
                {
                    res.push_back( revNum[k-1] );
                }
            }
        }

        return res;
    }
};