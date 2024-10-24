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
    void TransformTree(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 || !root2) return;
        if(!root1->left && !root1->right || !root2->left && !root2->right) return;
        int c1l = -1, c2l = -1, c1r = -1, c2r = -1;

        if(root1->left) c1l = root1->left->val;
        if(root1->right) c1r = root1->right->val;
        if(root2->left) c2l = root2->left->val;
        if(root2->right) c2r = root2->right->val;

        if(c1l == c2r && c1r == c2l)
        {
            //flip
            TreeNode* temp1 = root1->right;
            root1->right = root1->left;
            root1->left = temp1;
        }

        //just call next function
        TransformTree(root1->left, root2->left);
        TransformTree(root1->right, root2->right);
    }

    bool dfs(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 && !root2) return true;
        if(!root1) return false;
        if(!root2) return false;
        
        if(root1->val != root2->val) return false;

        return dfs(root1->left, root2->left) && dfs(root1->right, root2->right);  
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        TransformTree(root1, root2);
        return dfs(root1, root2);
    }
};