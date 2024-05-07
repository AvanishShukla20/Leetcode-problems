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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL)
        {
            TreeNode* t = new TreeNode(val);
            return t;
        }
        int a = 0; // 0 for left
        TreeNode* temp = root;
        TreeNode* prev = root;
        while(temp)
        {
            if(temp -> val < val)
            {
                prev = temp;
                temp = temp->right;
                a = 1;
            }
            else 
            {
                prev = temp;
                temp = temp->left;
                a = 0;
            }
        }
        TreeNode* t = new TreeNode(val);

        if(a == 0) prev->left = t;
        else prev ->right = t;

        return root; 
    }
};