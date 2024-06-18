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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        {
            TreeNode* n = new TreeNode(val);
            n->left = root;
            return n;
        }

        queue<pair<TreeNode* , int>> q;
        q.push({root, 1});

        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int step = q.front().second;
            q.pop();

            if(step == depth - 1)
            {
                TreeNode* l = node->left;
                TreeNode* r = node->right;

                node->left = new TreeNode(val);
                node->right = new TreeNode(val);

                node->left->left = l;
                node->right->right = r;
            }
            else
            {
                if(node->left) q.push({node->left, step + 1});
                if(node->right) q.push({node->right, step + 1});
            }
           
        }
        return root;
    }
};