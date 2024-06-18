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

    void markParents(TreeNode* node, unordered_map<TreeNode*, TreeNode*>& parent, int& n, int start, TreeNode*& snode)
    {
        n += 1;
        if(node->val == start) snode = node;
        if(node->left) 
        {
            parent[node->left] = node;
            markParents(node->left, parent, n, start, snode);
        }
        if(node->right)
        {
            parent[node->right] = node;
            markParents(node->right, parent, n, start, snode);
        }
    }
    int amountOfTime(TreeNode* root, int start) {

        queue<pair<TreeNode*, int>> q;
        int n = 0;
        unordered_map<TreeNode*, TreeNode* > parent;
        parent[root] = NULL;
        TreeNode* snode;
        markParents(root, parent, n, start, snode);
        cout<<"n : "<<n<<endl;
        unordered_set<int> vis;

        q.push({snode, 0});
        TreeNode* node; 
        int level;

        while(!q.empty())
        {
            node = q.front().first;
            level = q.front().second;
            q.pop();

            vis.insert(node->val);

            if(node->left  && vis.find(node->left->val) == vis.end())
            {
                q.push({node->left, level+1});
            }
            if(node->right && vis.find(node->right->val) == vis.end())
            {
                q.push({node->right, level+1});
            }
            if(parent[node] != NULL && vis.find(parent[node]->val) == vis.end())
            {
                q.push({parent[node], level+1}); 
            }
        }
        return level;
    }
};