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
    class BstIterator{
        stack<TreeNode* > st;

        /* true -> before and false -> next */
        bool reverse = true;
        public:

        BstIterator(TreeNode* root, bool isReverse)
        {
            reverse = isReverse;
            pushInStack(root);
        }

        void pushInStack(TreeNode* node)
        {
            while(node)
            {
                st.push(node);
                if(reverse == true) node = node->right;
                else node = node->left;
            }
        }

        int next()
        {
            TreeNode* temp = st.top();
            st.pop();
            if(reverse == true) pushInStack(temp->left);
            else pushInStack(temp->right);
            return temp->val;
        }

        bool hasnext()
        {
            return !st.empty();
        }

    };
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BstIterator leftptr(root, false);
        BstIterator rightptr(root, true);

        int i= leftptr.next();
        int j = rightptr.next();

        while(i < j)
        {
            if(i + j == k) return true;
            else if(i + j< k) i = leftptr.next();
            else j = rightptr.next();

        }
        return false;
    }
};