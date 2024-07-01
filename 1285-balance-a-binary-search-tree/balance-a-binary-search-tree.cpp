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
    void inorder(vector<TreeNode*>& sortedList, TreeNode* root)
    {
        if(!root) return;
        inorder(sortedList, root->left);
        sortedList.push_back(root);
        inorder(sortedList, root->right);

    }

    TreeNode* buildTree(vector<TreeNode*>& sortedList, int left, int right)
    {
        if(left > right) return NULL;
        int mid = left + (right-left)/2;

        TreeNode* nroot = new TreeNode(sortedList[mid]->val);
        nroot->left = buildTree(sortedList, left, mid -1);
        nroot->right = buildTree(sortedList, mid+1, right);
        return nroot;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sortedList;

        // do inorder travesal to find sorted order of node of given BST
        inorder(sortedList, root);

        int n = sortedList.size();
        TreeNode* ans = buildTree(sortedList, 0, n - 1);

        return ans;



    }
};