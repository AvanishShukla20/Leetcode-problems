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
class BalPair{
    public :
    int ht;
    bool isBal;
};
class Solution {
public:
    BalPair func(TreeNode* curr)
    {

        if(curr == NULL)
        {
            BalPair base;
            base.ht = 0; //because height is calculated by no of nodes here
            // ht = -1 is done when calculting height by edges is done
            base.isBal = true;
            return base;
        }

        BalPair leftP = func(curr ->left);
        BalPair rightP = func(curr ->right);

        BalPair myPair;
        //calculting height of tree from our curr node
        myPair.ht = max(leftP.ht,rightP.ht) + 1;
        //calculating that tree till covered is balanced or not
        myPair.isBal = abs(leftP.ht - rightP.ht) <= 1 && leftP.isBal && rightP.isBal ;
        return myPair;
    }

    bool isBalanced(TreeNode* root) {
        BalPair x = func(root);
        return x.isBal; 
    }
};