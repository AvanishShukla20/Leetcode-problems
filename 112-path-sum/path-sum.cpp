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
    bool isleaf(TreeNode* node)
    {
        return node->left == NULL && node->right == NULL;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return {};
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, root->val});
        
        while(!Q.empty())
        {
            int size = Q.size();
            for(int i=1; i<=size; i++)
            {
                auto p = Q.front();
                Q.pop();
                TreeNode* curr = p.first;
                int Sumsf =  p.second;
                if(Sumsf == targetSum && isleaf(curr)) return true;
                if(curr->left) Q.push({curr->left, Sumsf + curr->left->val});
                if(curr->right) Q.push({curr->right, Sumsf + curr->right->val});
            }
        }
        return false;
    }
};