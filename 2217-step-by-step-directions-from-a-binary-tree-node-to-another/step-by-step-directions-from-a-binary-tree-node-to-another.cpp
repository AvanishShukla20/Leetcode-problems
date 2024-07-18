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

    TreeNode* lca(TreeNode* root, TreeNode*& a, TreeNode*& b)
    {
        if(!root) return NULL;
        else if(root == a || root == b) return root;

        TreeNode* left = lca(root->left, a, b);
        TreeNode* right = lca(root->right, a, b);

        if(left && right) return root;
        else if(left != NULL) return left;
        else return right;
    }

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int& startValue,int& destValue, TreeNode*& start, TreeNode*& dest)
    {
        if(!root) return;

        if(root->val == startValue) start = root;
        if(root->val == destValue) dest = root;

        if(root->left)
        {
            parent[root->left] = root;
            markParents(root->left, parent,startValue, destValue, start, dest);
        }
        if(root->right)
        {
            parent[root->right] = root;
            markParents(root->right, parent,startValue, destValue, start, dest);
        }
    }


    string getDirections(TreeNode* root, int startValue, int destValue) {

        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* start = NULL;
        TreeNode* dest = NULL;
        markParents(root, parent, startValue, destValue, start, dest);

        
        TreeNode* lcanode = lca(root, start, dest);
        cout<<start->val<<" "<<dest->val<<" "<<lcanode->val<<endl;
        // going up from start to lca

        string ans1 = "";
        queue<TreeNode*> q;
        q.push(start);

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            if(it == lcanode) break;
            ans1 += 'U';
            q.push(parent[it]);
        }
        cout<<" ans1 :"<<ans1<<endl;

        //going up from dest to lca
        queue<TreeNode*> q1;
        string ans2 = "";
        q1.push(dest);
        while(!q1.empty())
        {
            auto it = q1.front();
            q1.pop();
            if(it == lcanode) break;
            if(parent[it]->left == it)
            {
                ans2 += 'L';
            }
            else ans2 += 'R';
            q1.push(parent[it]); 
        }

        reverse(ans2.begin(), ans2.end());

        string ans = ans1 + ans2;
        return ans;


    }
};