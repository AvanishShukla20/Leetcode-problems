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
    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        set<int> levels;

        while(!q.empty())
        {
            auto pt = q.front();
            q.pop();
            int level = pt.second;
            if(!levels.contains(level))
            {
                ans = pt.first->val;
                levels.insert(level);
            }

            if(pt.first ->left) q.push({pt.first -> left, level + 1});
            if(pt.first ->right) q.push({pt.first -> right, level + 1});
        }
        return ans;
    }
};