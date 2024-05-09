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
    unordered_map<int, int> mpp;
    TreeNode* constructTree(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int inStart, int inEnd)
    {
        if(pStart > pEnd || inStart > inEnd)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[pStart]);
        int idx = mpp[preorder[pStart]];

        int numberofNodesOnLeftside  = idx - inStart;

        TreeNode* leftsubTree = constructTree(preorder,pStart + 1, pStart + numberofNodesOnLeftside,inorder, inStart, idx - 1);

        TreeNode* rightsubTree = constructTree(preorder,pStart + numberofNodesOnLeftside + 1, pEnd,inorder, idx + 1, inEnd);

        root ->left = leftsubTree;
        root->right = rightsubTree;

        return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n =  preorder.size(), m = inorder.size();
        for(int i=0; i<inorder.size(); i++) 
        {
            mpp[inorder[i]] = i;
        }
        TreeNode* root = constructTree(preorder, 0, n-1, inorder, 0, m - 1);
        return root;
    }
};