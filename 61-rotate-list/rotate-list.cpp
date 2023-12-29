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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == NULL || head->next == NULL) return head;
        ListNode* temp = head;
        int n = 0;
        while (temp != NULL) {
            temp = temp->next;
            n++;
        }

        if(k >= n)
        {
            k = k % n;
        }
        ListNode* last = head;
        for (int i = 1; i < n - k; i++) {
            last = last->next;

        }
        ListNode* p= last;

        while(p->next != NULL)
        {
            p = p->next;
        }

        p->next = head;
        head = last->next;
        last->next = NULL;
        return head;

    }
};