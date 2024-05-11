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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        TreeNode* curr= root;
        while(curr)
        {
            
            if(curr->left)
            {
                TreeNode* leftchild = curr->left;
                while(leftchild->right)
                {
                    leftchild = leftchild->right;
                }

                leftchild->right = curr;
                /*delete connection and move to left*/

                TreeNode* temp = curr;
                curr = curr->left;
                temp->left = NULL;
            }
            else
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }

        }
        return ans;
    }
};