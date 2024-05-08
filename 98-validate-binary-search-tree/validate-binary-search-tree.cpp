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
    bool isValid(TreeNode* root, long low, long high, bool t)
    {
        if(root == NULL) return true;
        else if(root->val > low && root->val < high) t = true;
        else t = false;

        bool t2 = isValid(root->left, low, root->val, t);
        bool t3 = isValid(root->right, root->val, high, t);

        return t && t2 && t3;
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(!root->left && !root->right) return true;
        bool t;
        return isValid(root, LONG_MIN, LONG_MAX,t);
    }
};