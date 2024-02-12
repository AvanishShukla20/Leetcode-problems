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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> Q;
        Q.push(root);

        vector<vector<int>> ans;

        while(Q.size() > 0)
        {
            int countOfNodes = Q.size();
            vector<int> temp(countOfNodes);
            for(int i=0; i< countOfNodes; i++)
            {
                TreeNode* curr = Q.front();
                Q.pop();
                temp[i] = curr->val;
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};