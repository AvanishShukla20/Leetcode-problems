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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* i = head;
        ListNode* j = head->next;
        ListNode* k = NULL;
        if(j->next != NULL)
        {
            k = j->next;
        }

        i->next = NULL;

        while(k != NULL)
        {
            j->next = i;
            i = j;
            j = k;
            k = k->next;
        }

        j->next = i;  

        return j;

        /* the fatal mistake is
        1->2->3->4 If
        You will apply above logic then result will be like 1->2->1
        */
    }
};