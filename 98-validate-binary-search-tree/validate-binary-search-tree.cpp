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
    bool isValid(TreeNode* root, long low, long high)
    {
        if(root == NULL) return true;
        if(root->val <= low || root->val >= high) return false;

        bool t2 = isValid(root->left, low, root->val);
        bool t3 = isValid(root->right, root->val, high);

        return t2 && t3;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return isValid(root, LONG_MIN, LONG_MAX);
    }
};