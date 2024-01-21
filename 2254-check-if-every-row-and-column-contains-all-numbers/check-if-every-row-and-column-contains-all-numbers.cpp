class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {

        sort(matrix.begin(), matrix.end());
        set<int> s1;
        for(int i=1; i<= matrix.size(); i++) s1.insert(i);

         // column check
        for(int i=0; i< matrix.size(); i++)
        {
            set<int>s(s1.begin(),s1.end());

            for(int j=0; j<matrix.size(); j++)
            {
                if(s.find(matrix[j][i]) == s.end())return false;
                s.erase(matrix[j][i]);  
            }

        }

        //row check
        for(int i=0; i< matrix.size(); i++)
        {
            set<int>s(s1.begin(),s1.end());
            for(int j=0; j<matrix.size(); j++)
            {
                if(s.find(matrix[i][j]) == s.end()) return false;
                s.erase(matrix[i][j]); 

            }
        }

        return true;
    }
};