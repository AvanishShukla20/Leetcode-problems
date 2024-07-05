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
    ListNode* mergeNodes(ListNode* head) {
        if(!head) return NULL;
        int sum = 0;
        bool headmade = 0;
        head = head->next;
        ListNode* nhead = new ListNode();
        ListNode* temp = NULL;
        while(head)
        {
            sum += head->val;
            if(head->val == 0)
            {
                if(!headmade)
                {
                    nhead->val = sum;
                    temp = nhead;
                    headmade = 1;
                    sum = 0;
                }
                else
                {
                    temp->next = new ListNode(sum);
                    temp = temp->next;
                    sum = 0;
                }
            }
            head = head->next;
        }

        return nhead;
    }
};