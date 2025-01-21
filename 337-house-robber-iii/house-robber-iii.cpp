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
    pair<int, int> solve(TreeNode* root)
    {
        if(!root)
        {
            return {0, 0};
        }
        pair<int, int> leftPair  = solve(root->left);
        pair<int, int> rightPair = solve(root->right);

        // {p, q} -> p is maxsum obtained if i include root q is maxsum if i don't include q

        //including the root i will add values gotten by not including the children
        int lsum = root->val + leftPair.second + rightPair.second;
        // not including the root
        int rsum = max(leftPair.first, leftPair.second) + max(rightPair.first, rightPair.second);

        return {lsum, rsum};

    }
    int rob(TreeNode* root) {
        pair<int, int> ans = solve(root);

        return max(ans.first, ans.second);
    }
};