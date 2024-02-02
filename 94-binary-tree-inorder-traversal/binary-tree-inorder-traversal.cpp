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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        
        //note this method OF USING A WHILE LOOP WITH ALWAYS TRUE CONDITION
        while(true)
        {
            if(curr != NULL)
            {
                st.push(curr);
                curr = curr -> left;
            }
            else
            {
                //if curr is NULL
                if(st.empty()) break;

                ans.push_back(st.top()->val);

                curr = st.top() -> right;

                st.pop();
            }
        }
        return ans;
    }
};