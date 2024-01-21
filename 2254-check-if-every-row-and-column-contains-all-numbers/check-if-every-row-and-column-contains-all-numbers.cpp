class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        //we will use two sets and We will not initialise any of them in beginning 
        set<int> sRow,sCol;
     
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix.size(); j++)
            {
                if(sRow.find(matrix[i][j]) != sRow.end()) return false;
                else sRow.insert(matrix[i][j]);
                //no need to reinitialise the set multiple times as you were doing in your previous worst case code

                if(sCol.find(matrix[j][i]) != sCol.end()) return false;
                else sCol.insert(matrix[j][i]);
            }
            //THIS STEP YOU ALWAYS FORGET-> Do as it saves Lots of memory ->
            sRow.clear();
            sCol.clear();
        }
        return true;
    }
};