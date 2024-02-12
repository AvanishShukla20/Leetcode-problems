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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         if(root == NULL) return {};
        queue<TreeNode*> Q;
        Q.push(root);
        int idx = -1;
        int flag = 0;
        vector<vector<int>> ans;

        while(Q.size() > 0)
        {
            int countOfNodes = Q.size();
            vector<int> temp(countOfNodes);
            for(int i=0; i< countOfNodes; i++)
            {
                TreeNode* curr = Q.front();
                Q.pop();
                if(flag == 1) idx = countOfNodes - i - 1;
                else idx = i;
                temp[idx] = curr->val;
                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
            }

            flag = !flag;
            ans.push_back(temp);
        }

        return ans;
    }
};