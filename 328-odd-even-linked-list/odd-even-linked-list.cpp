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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* temp = head;
        ListNode* prev = head;
        ListNode* curr = head->next;

        int cnt = 1;
        while(temp->next)
        {
            temp = temp->next;
            cnt++;
        }
        if(cnt <= 2) return head;
        int runloop = 0;

        while(curr != NULL && runloop < cnt/2)
        {
            prev->next = curr->next;
            prev = prev->next;
            temp -> next = curr;
            temp = curr;
            temp->next = NULL;
            curr = prev;
            curr = curr->next;
            runloop++;
        }
        return head;
    }
};