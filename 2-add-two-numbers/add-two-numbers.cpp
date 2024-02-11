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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        ListNode* head = ans;

        int carry = 0;
        int sum ;
        while(l1 || l2 )
        {
            sum = 0;
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            sum += carry;
            carry = sum/10;
            ListNode* curr = new ListNode();
            curr->val = sum%10;
            curr->next = NULL;
            temp->next = curr;
            temp = curr;  
        }
        if(sum > 9 && carry != 0)
        {
            ListNode* curr = new ListNode;
            curr->val = 1;
            curr->next = NULL;
            temp->next = curr;
        }
        return head->next;
    }
};