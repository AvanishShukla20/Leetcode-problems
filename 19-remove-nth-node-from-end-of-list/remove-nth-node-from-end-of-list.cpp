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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt =0;
        ListNode* t = head;
        while(t)
        {
            cnt++;
            t=t->next;
        }

        int d = cnt-n;
        cout<<d<<endl;
        if(d == 0) return head->next;

        ListNode* m = head;
        ListNode* g = NULL;

        while(d--)
        {
            g = m;
            m=m->next;
        }
        //cout<<m->val<<endl;
        ListNode* next = m->next;
        g->next = next;
        return head;
    }
};