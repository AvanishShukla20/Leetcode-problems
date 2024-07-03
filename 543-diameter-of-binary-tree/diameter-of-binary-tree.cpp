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
    int pathSeen(TreeNode* root, int& ans)
    {
        if(root == NULL) return 0;

        int maxLeftPath  =  pathSeen(root->left, ans);
        int maxRightPath = pathSeen(root->right, ans);

        ans = max(ans, maxLeftPath + maxRightPath);

        //Send the max path which came from any one of left or right side

        return 1 + max(maxLeftPath, maxRightPath);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int ans = 0;
        int x = pathSeen(root, ans);
        return ans;
    }
};