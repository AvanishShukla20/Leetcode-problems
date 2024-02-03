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
    void calculateDepth(TreeNode* curr, int count,int& ans)
    {
        if(curr->left == NULL and curr->right == NULL)
        {
            if(count > ans) ans = count;   
            return;
        }

        if(curr->left != NULL)calculateDepth(curr -> left, count+1, ans);
        if(curr->right != NULL)calculateDepth(curr -> right, count+1, ans); 
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0, count = 1;
        calculateDepth(root, count, ans);
        return ans;
        
        
    }
};