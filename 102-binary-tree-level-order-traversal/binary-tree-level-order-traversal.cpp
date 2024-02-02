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
       //iterative version ->

       queue<TreeNode* > q;
       vector<vector<int>> ans;
       if(root == NULL) return{};
       q.push(root);
       q.push(NULL);

       while(!q.empty())
       {
           vector<int> v;
           TreeNode* curr = q.front();
           while(curr != NULL)
           {
               v.push_back(curr->val);
               if(curr -> left != NULL) q.push(curr->left);
               if(curr -> right != NULL) q.push(curr->right);
               q.pop();
               curr = q.front();
           }

           ans.push_back(v);
           // now curr == null 
            if(q.back() != NULL)
            {
                q.pop();
                q.push(NULL);
            }
            else
            {
                break;
            }
           
       }
        return ans;
    }
};