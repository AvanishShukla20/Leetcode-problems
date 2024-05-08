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
    TreeNode* attachNodes(TreeNode* curr)
    {
            if(!curr->left) return curr->right;
            else if(!curr->right) return curr->left;

            TreeNode* temp = curr;

            temp = temp->left;
            while(temp->right) temp = temp->right;
            temp->right = curr->right;
            return curr->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        if(root->val == key) return attachNodes(root);
        TreeNode* t = root;
        while(root)
        {
            if(root->val > key)
            {
                if(root->left && root->left->val == key)
                {
                    root->left = attachNodes(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else
            {
                if(root->right && root->right->val == key)
                {
                    root->right = attachNodes(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }   
        }
        return t;
        
    }
};