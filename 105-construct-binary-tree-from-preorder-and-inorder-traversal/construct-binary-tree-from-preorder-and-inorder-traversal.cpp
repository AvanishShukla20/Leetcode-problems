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
    
    TreeNode* createTree(int preStart, int preEnd, vector<int>& preorder, int inStart, int inEnd, vector<int>& inorder)
    {
        if(preEnd < preStart || inEnd < inStart) return NULL;
        TreeNode* currRoot = new TreeNode(preorder[preStart]);

        int rootIdx = inorderIdx[preorder[preStart]];
        int nodesLeft = rootIdx - inStart;

        currRoot -> left = createTree(preStart+1, preStart+nodesLeft, preorder,inStart ,rootIdx - 1 ,inorder);
        currRoot -> right = createTree(preStart + nodesLeft + 1, preEnd, preorder, rootIdx+1, inEnd, inorder);

        return currRoot;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i=0; i<inorder.size(); i++)
        {
            inorderIdx[inorder[i]] = i;
        }

        TreeNode* root = createTree(0,preorder.size() - 1, preorder, 0, inorder.size() - 1,inorder);
        return root;



        
    }
};