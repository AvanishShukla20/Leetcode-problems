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
    //at each step we check the symmetricity on both left and right side of a node

    bool helper(TreeNode* node1, TreeNode* node2)
    {
        if(node1 == NULL && node2 == NULL) return true;
        else if(node1 == NULL || node2 == NULL) return false;

        if(node1->val != node2->val) return false;

        bool fromleftSide  = helper(node1->left, node2->right);
        bool fromrightSide = helper(node1->right, node2->left);

        return fromleftSide && fromrightSide;
    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;

        return helper(root->left, root->right);
    }
};