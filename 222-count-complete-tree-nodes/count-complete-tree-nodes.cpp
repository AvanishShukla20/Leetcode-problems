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
    int lHeight(TreeNode* curr)
    {
        if(curr == NULL) return 0;
        //recursive -> 
        int received = lHeight(curr->left);
        if(curr) received ++;
        return received;
    }

    int rHeight(TreeNode* curr)
    {
        // recursive
        if(curr == NULL) return 0;
        int received = rHeight(curr->right);
        if(curr) received ++;
        return received;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;


        int leftHeight = lHeight(root);
        int rightHeight = rHeight(root);

        if(leftHeight == rightHeight)
        {
            //no further countNodes function call 
            /* 0(n) -> return pow(2, leftHeight) - 1;*/
            //O(1) ->
            return (1<<leftHeight) - 1;
        }
        else
        {
            return 1 + countNodes(root->left) + countNodes(root->right);
        }

    }
};