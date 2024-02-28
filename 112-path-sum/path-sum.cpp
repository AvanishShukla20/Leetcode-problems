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
    bool isPathExist(TreeNode* node, int target)
    {
        if(node->left == NULL && node->right == NULL)
        {
            return (node->val == target) ? true : false;
        }

        /*
        efficient and time saving technique
        always remember -> subtract target by node's value whenever sending it to next
        left or right call  
        */
        bool x = false,y = false;
        if(node->left)  x = isPathExist(node->left, target - node->val);
        if(node->right) y = isPathExist(node->right, target - node->val);

        return x || y;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        return isPathExist(root,targetSum);
    }
};