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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> allchilds;

        TreeNode* root = NULL;

        int n = descriptions.size();
        for(int i = 0; i < n; i++)
        {
            int par = descriptions[i][0];
            int child = descriptions[i][1];
            int side = descriptions[i][2];

            if(mpp.find(par) == mpp.end())
            {
                mpp[par] = new TreeNode(par);
            }

            if(mpp.find(child) == mpp.end())
            {
                mpp[child] = new TreeNode(child);
            }

            if(side == 1)  mpp[par]->left = mpp[child];
            else  mpp[par]->right = mpp[child];

            allchilds.insert(child);
        }

        for(auto &it : descriptions)
        {
            if(allchilds.find(it[0]) == allchilds.end())
            {
                root = mpp[it[0]];
            }
        }
        return root;

    }
};