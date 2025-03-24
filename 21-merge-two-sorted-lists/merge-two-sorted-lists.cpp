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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode* l = list1, *lnext = NULL;
        ListNode* r = list2, *rnext = NULL;

        ListNode* newhead = NULL, *temp = NULL;

        if(l->val <= r->val) 
        {
            temp = l;
            l = l->next;
        }
        else 
        {
            temp = r;
            r = r->next;
        }

        newhead = temp;

        while(l && r)
        {
        lnext = l->next;
        rnext = r->next;

        if(l->val <= r->val)
        {
            temp->next = l;
            l = lnext;
            temp = temp->next;
        }
        else
        {
            temp->next = r;
            r = rnext;
            temp=temp->next;
        }

        }

        while(l)
        {
            temp->next = l;
            l = l->next;
            temp = temp->next;
        }

        while(r)
        {
            temp->next = r;
            r = r->next;
            temp = temp->next;
        }

        return newhead;
    }
};