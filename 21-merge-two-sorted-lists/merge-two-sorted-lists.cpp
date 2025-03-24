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

        ListNode* l = list1;
        ListNode* r = list2;

        // ListNode* newhead = NULL, temp = NULL; // Because->newhead is pointer while temp is taken as object in tthis type off declaration

        ListNode* newhead = NULL;
        ListNode* temp = NULL;
         // newhead is now a pointer and temp is also a pointer

         
        while(l && r)
        {

        if(l->val <= r->val)
        {
            if(newhead == NULL)
            {
                newhead = new ListNode(l->val);
                temp = newhead;
            }
            else
            {
                temp->next = new ListNode(l->val);
                temp = temp->next;
            }
            l = l->next;
        }
        else
        {
            if(newhead == NULL)
            {
                newhead = new ListNode(r->val);
                temp = newhead;
            }
            else
            {
                temp->next = new ListNode(r->val);
                temp = temp->next;
            }
            r = r->next;
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