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
    vector<vector<int>> ans;
    void findPath(TreeNode* root, vector<int>& path,int& sum, int targetSum)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            sum += root->val; 
            if(sum == targetSum)
            {
                path.push_back(root->val);
                ans.push_back(path);
                path.pop_back();     
            }
            sum -= root->val;
            return ;
        }

        path.push_back(root->val);
        sum += root->val;

        findPath(root->left, path,sum, targetSum);
        findPath(root->right, path,sum, targetSum);

        sum -= root->val;
        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        vector<int> path;
        int sum = 0;
        findPath(root, path, sum ,targetSum);
        return ans;
    }
};