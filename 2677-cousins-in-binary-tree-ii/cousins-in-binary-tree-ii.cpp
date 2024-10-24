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

        //another bfs 
        // It uses size of queue at each level to determine no of nodes at each level.

        queue<TreeNode*> q2;
        q2.push(root);
        int lvl = 1;
        while(!q2.empty())
        {
            int nodesAtlvl = q2.size();

            for(int i=0; i<nodesAtlvl; i++)
            {
                auto node = q2.front();
                q2.pop();
                int siblingSum = 0;
                if(node->left) siblingSum += node->left->val;
                if(node->right) siblingSum += node->right->val;

                if(node->left)
                {
                    node->left->val = lvlsum[lvl] - siblingSum;
                    q2.push(node->left);
                }
                if(node->right)
                {
                    node->right->val = lvlsum[lvl] - siblingSum;
                    q2.push(node->right);
                }

            }
            lvl++;
        }
        root->val = 0;
        return root;
    }
};