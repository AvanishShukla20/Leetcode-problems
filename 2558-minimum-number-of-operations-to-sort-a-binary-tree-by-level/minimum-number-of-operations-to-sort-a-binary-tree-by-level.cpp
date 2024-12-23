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
    int minOpr(vector<int>& arr)
    {
        int n = arr.size();
        vector<pair<int, int>> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({arr[i], i});
        }
        sort(vec.begin(), vec.end());
        vector<int> mark(n, 0);
        int ans = 0;
        for(int i=0; i<vec.size(); i++)
        {
            if(i == vec[i].second || mark[i] == true) continue;
            else
            {
                int j = i, size = 0;
                while(mark[j] == false)
                {
                    size++;
                    mark[j] = true;
                    j = vec[j].second;
                }
                ans += (size - 1);
            }
        }
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        if(!root) return 0;
        int ans = 0;
        queue<TreeNode*> pq;
        pq.push(root);
        while(!pq.empty())
        {
            int size = pq.size();
            cout<<size<<endl;
            vector<int> vec(size);
            for(int i=0; i<size; i++)
            {
                auto t = pq.front();
                pq.pop();
                vec[i] = t->val;

                if(t->left != NULL) pq.push(t->left);
                if(t->right != NULL) pq.push(t->right);
            }

            int value = minOpr(vec);
            cout<<vec.size()<<"value : "<<value<<endl;
            ans += value;
        }
        return ans;
    }
};