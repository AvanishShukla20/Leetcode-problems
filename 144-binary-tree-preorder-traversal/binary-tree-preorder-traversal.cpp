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
    vector<int> preorderTraversal(TreeNode* root) {
      //when we want to keep track of vesited ones We always use stack 
      stack<TreeNode*> st;
      vector<int> ans;
      if(root == NULL) return {};
      
      st.push(root);

      while(!st.empty())
      {
        TreeNode* curr = st.top();
        ans.push_back(st.top() -> val);
        st.pop();
        if(curr -> right != NULL) st.push(curr -> right);
        if(curr -> left != NULL) st.push(curr -> left);
      }
      return ans ;  
    }
};