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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        stack<TreeNode* > st;
        st.push(root);
        vector<int> ans;
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            ans.push_back(st.top() -> val);
            st.pop();
            if(curr -> left != NULL) st.push(curr -> left);
            if(curr -> right != NULL) st.push(curr -> right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};