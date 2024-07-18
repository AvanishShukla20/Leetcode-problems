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
    

    vector<int> helper(TreeNode* root,int& distance, int& cnt)
    {
        if(!root) return {};
        else if(!root->left && !root->right) return {1};

        vector<int> a = helper(root->left, distance, cnt);
        vector<int> b = helper(root->right, distance, cnt);
        vector<int> vec;
        for(int i = 0; i< a.size(); i++)
        {
            for(int j = 0; j<b.size(); j++)
            {
                if(a[i] + b[j] <= distance) cnt++;    
            }
        }

        for(int i =0; i<a.size(); i++) vec.push_back(a[i]+1);
        for(int i = 0;i <b.size(); i++) vec.push_back(b[i] + 1);

        return vec;
    }


    

    int countPairs(TreeNode* root, int distance) {
        int cnt = 0;
        vector<int> r = helper(root,distance, cnt);

        return cnt;

    }
};