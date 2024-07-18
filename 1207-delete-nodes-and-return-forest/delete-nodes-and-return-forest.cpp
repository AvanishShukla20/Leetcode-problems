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
    TreeNode* dfs(TreeNode* root,vector<TreeNode*>& store, unordered_set<int>& st)
    {
        // doing deletion task in bottom Up Approach i.e task performing while returning from call ....is mostly feasible in almost all tree problems
        if(!root) return NULL;

        root->left = dfs(root->left, store, st);
        root->right = dfs(root->right, store, st);

        // perform task

        if(st.find(root->val) != st.end())
        {
            if(root->left) store.push_back(root->left);
            if(root->right) store.push_back(root->right);
            return  NULL;
        }
        else return root;


    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        vector<TreeNode*> store;
        unordered_set<int> st;

        for(auto &it : to_delete) st.insert(it);

        dfs(root, store, st);

        if(st.find(root->val) == st.end())
        {
            store.push_back(root);
        }
        
        return store;
    }
};