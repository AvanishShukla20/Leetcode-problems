/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node->next == NULL) node=NULL;
        
        ListNode* l = node;
        ListNode* pr;
        while(l->next != NULL)
        { 
            int v = l->next->val;
            int t = l->val;
            l->val = v;
            l->next->val = t;
            pr = l;
            l=l->next;
        }
        pr->next = NULL;
    }
};