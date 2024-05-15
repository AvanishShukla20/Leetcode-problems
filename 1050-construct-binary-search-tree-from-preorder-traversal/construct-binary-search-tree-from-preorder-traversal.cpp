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

    TreeNode* giveBst(vector<int>& preorder, int& idx, int Bound)
    {
        if(idx ==preorder.size() || preorder[idx] > Bound ) return NULL;

        TreeNode* root = new TreeNode(preorder[idx]);
        idx += 1;

        root->left = giveBst(preorder, idx, root->val);
        root->right = giveBst(preorder, idx, Bound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        int Bound = INT_MAX,idx = 0;

        return giveBst(preorder, idx, Bound);
    }
};