/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lca(TreeNode* root, TreeNode*& a, TreeNode*& b)
    {
        if(!root) return NULL;
        else if(root == a || root == b) return root;

        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);

        if(left && right) return root;
        else if(left != NULL) return left;
        else return right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lca(root, p, q);
    }
};