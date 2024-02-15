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
    //going dfs traversal
    TreeNode* findLCA(TreeNode* curr, TreeNode* p, TreeNode* q)
    {
        if(curr == NULL || curr == p || curr == q) return curr;

        TreeNode* l = findLCA(curr->left,p,q);
        TreeNode* r = findLCA(curr->right,p,q);

        if(r == NULL) return l; 
        else if(l == NULL) return r;
        // it means from both sides the nodes are returned in else case ->
        else return curr;
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        return findLCA(root, p, q);
    }
};