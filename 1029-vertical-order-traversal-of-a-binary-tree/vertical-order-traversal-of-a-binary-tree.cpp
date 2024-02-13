/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void helper(TreeNode* curr, int colNo, int rowNo, map<int, vector<pair<int,int>>>& mpp)
    {
        if(curr == nullptr) return;

        mpp[colNo].push_back({rowNo, curr->val});
        //go left
        helper(curr->left, colNo-1, rowNo+1, mpp);
        //go right
        helper(curr->right, colNo+1, rowNo+1, mpp);

    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>>  res;
        if(root == nullptr) return res;

        /* 
        mpp key -> columnNo 
        mpp value -> a vector of pair of elements where first element is rowNo and second is node itself */

        map< int, vector<pair<int, int>>> mpp;
        helper(root, 0, 0, mpp);

        for(auto p : mpp)
        {
            //sorting kind of 2d array i.e vector of pairs,  with comparator function
            vector<pair<int, int>> temp = p.second;

            sort(temp.begin(), temp.end(), [](pair<int, int>& p1, pair<int,int>& p2)
            {
                return (p1.first < p2.first) || ((p1.first == p2.first) && (p1.second < p2.second));
            });

            
            vector<int> columns;

            for(auto i : temp)
            {
                columns.push_back(i.second);
            }
            
            res.push_back(columns);
        }
        return res;

    }
};