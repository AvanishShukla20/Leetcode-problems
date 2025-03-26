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
    
    ListNode *detectCycle(ListNode *head) {
        // Idea : total distance from head and start of Cycle(X)  = total distance from Point of meet of slow == fast and the start of Cycle(X)
        if(!head || !head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }

        if(fast == NULL || fast->next == NULL) return NULL;
        ListNode* p = head;

        while(p != slow)
        {
            p= p->next;
            slow = slow->next;
        }

        return p;
    }
};