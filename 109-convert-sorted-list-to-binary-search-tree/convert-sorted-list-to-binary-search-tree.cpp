/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

    TreeNode* buildTree(ListNode* low)
    {
        if(low == NULL) return NULL;
        if(low->next == NULL) return new TreeNode(low->val);
        ListNode* slow = low; ListNode* prev = NULL;
        ListNode* fast = low;

        while(fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        TreeNode* root = new TreeNode(slow->val);
        prev->next = NULL;
        root->left = buildTree(low);
        root->right = buildTree(slow->next);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;

        return buildTree(head);
    }
};