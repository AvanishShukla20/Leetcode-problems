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
    
    void inorderdfs(TreeNode* root, int k,int& count , TreeNode*& ans)
    {
        if(!root->left && !root->right) 
        {
            count++;
            if(count == k)
            {
                ans = root;
            }
            return;
        }
        if(root->left) inorderdfs(root->left,k,count, ans);
        count++;
        if(count == k){
        ans = root;
        }
        if(root->right) inorderdfs(root->right, k,count, ans);
        return;
    }

    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL) return 0;
        TreeNode* ans = NULL;
        int count = 0;
        inorderdfs(root, k,count, ans);
        if(ans == NULL) return -1;
        else return ans->val;

        
    }
};