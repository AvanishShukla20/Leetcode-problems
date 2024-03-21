/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Function to populate the parent pointers
    void getParent(TreeNode* curr, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (curr == NULL) return;

        if (curr->left != NULL) {
            parent[curr->left] = curr;
            getParent(curr->left, parent);
        }
        if (curr->right != NULL) {
            parent[curr->right] = curr;
            getParent(curr->right, parent);
        }
    }

    // Function to find nodes at distance k from the target node
    void helperFunc(TreeNode* curr, int k, vector<int>& ans, unordered_map<TreeNode*, TreeNode*>& parent) {
        queue<TreeNode*> q;
        q.push(curr);
        unordered_set<TreeNode*> visitedNodes;
        visitedNodes.insert(curr);

        while (!q.empty()) {
            int size = q.size();
            if (k == 0) break;
            while (size > 0) {
                TreeNode* front = q.front();
                q.pop();

                if (front->left != NULL && visitedNodes.count(front->left) == 0) {
                    q.push(front->left);
                    visitedNodes.insert(front->left);
                }
                if (front->right != NULL && visitedNodes.count(front->right) == 0) {
                    q.push(front->right);
                    visitedNodes.insert(front->right);
                }

                if (parent.find(front) != parent.end() && visitedNodes.count(parent[front]) == 0) {
                    q.push(parent[front]);
                    visitedNodes.insert(parent[front]);
                }
                size--;
            }
            k--;
        }

        while (!q.empty()) {
            int value = q.front()->val;
            ans.push_back(value);
            q.pop();
        }
    }

    // Main function to find nodes at distance k from the target node
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if (root == NULL) return {};
        unordered_map<TreeNode*, TreeNode*> parent;
        getParent(root, parent);
        vector<int> ans;
        helperFunc(target, k, ans, parent);
        return ans;
    }
};