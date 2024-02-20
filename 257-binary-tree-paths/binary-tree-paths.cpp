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
    void getPaths(TreeNode* node, string path, vector<string>& ans)
    {
        if(node->left == NULL && node->right == NULL)
        {
            path += to_string(node->val);
            ans.push_back(path);
            return;
        }

        path += to_string(node->val)+"->";

        if(node->left)  getPaths(node->left, path, ans);
        if(node->right) getPaths(node->right, path, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return {""};
        vector<string> ans;
        string paths = "";
        getPaths(root, paths, ans);
        return ans;
    }
};