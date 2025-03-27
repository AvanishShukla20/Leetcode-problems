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
    ListNode* getseclast(ListNode* h)
    {
        ListNode* prev = NULL;
        while(h->next)
        {
            prev = h;
            h=h->next;
        }
        return prev;
    }
    int count(ListNode* he)
    {
        int cnt = 0;
        while(he)
        {
            he = he->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;
        int size = count(head);
        int m = k%size;
        while(m--)
        {
            ListNode* sec = getseclast(head);
            ListNode* temp = new ListNode(sec->next->val);
            sec->next = NULL;
            temp->next = head;
            head = temp;
        }

        return head;
    }
};