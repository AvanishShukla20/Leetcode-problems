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
    unordered_map<int, int> inorderIdx;
    TreeNode* createTree(vector<int>& inorder,int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd)
    {
        if(postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* currRoot = new TreeNode(postorder[postEnd]);

        int inRootIdx = inorderIdx[postorder[postEnd]];
        int nodesLeft = inRootIdx - inStart;

        
        currRoot->left = createTree(inorder, inStart, inRootIdx - 1, postorder, postStart, postStart + nodesLeft-1);
        currRoot->right = createTree(inorder, inRootIdx + 1,inEnd, postorder,postStart+nodesLeft, postEnd - 1);

        return currRoot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0; i<inorder.size(); i++)
        {
            inorderIdx[inorder[i]] = i;
        }

        TreeNode* root = createTree(inorder,0,inorder.size() - 1, postorder, 0, postorder.size()-1);
        return root;
    }
};