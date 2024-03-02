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
    bool isEvenOddTree(TreeNode* root) {

      queue<TreeNode*> Q;
      Q.push(root);
      bool isEven = true; 
      while(!Q.empty())
      {
            int size = Q.size();
            int prev;
            if(isEven) prev = INT_MIN;
            else prev = INT_MAX;
            //note in each iteration we will be having a list of nodes for a level
            while(size--)
            {
                TreeNode* curr = Q.front();
                Q.pop();
                //false conditions->
                if(isEven && (curr->val%2 == 0 || curr->val <= prev)) return false;
                if(!isEven && (curr->val%2 != 0 || curr->val >= prev)) return false;
                //update prev as next
                prev = curr->val;

                //push operations

                if(curr->left) Q.push(curr->left);
                if(curr->right) Q.push(curr->right);
                
            }
            isEven = !isEven;
      } 

      return true;
    }
};