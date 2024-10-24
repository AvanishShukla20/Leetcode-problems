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
    void dfs(TreeNode* root, int& lvl, unordered_map<TreeNode*, int>& mpp,unordered_map<int , int>& lvlsum)
    {
        if(!root) return;

        int sum = lvlsum[lvl];
        if(root->left) sum -= root->left->val;
        if(root->right) sum -= root->right->val;
        mpp[root->left] = sum;
        mpp[root->right] = sum;

        lvl += 1;
        if(root->left) dfs(root->left,lvl, mpp, lvlsum);
        if(root->right) dfs(root->right,lvl , mpp, lvlsum);
        lvl -= 1;

    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        unordered_map<int , int> lvlsum;
        
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        while(!q.empty())
        {
            auto lvl = q.front().first;
            auto node = q.front().second;
            q.pop();

            lvlsum[lvl] += node->val;

            if(node->left) q.push({lvl+1, node->left});
            if(node->right) q.push({lvl+1, node->right});
        }
        unordered_map<TreeNode*, int> mpp;
        int lvl = 1;
        dfs(root, lvl, mpp,lvlsum);

        for(auto it : mpp)
        {
            if(it.first) it.first->val = it.second;
        }
        root->val = 0;
        return root;
    }
};