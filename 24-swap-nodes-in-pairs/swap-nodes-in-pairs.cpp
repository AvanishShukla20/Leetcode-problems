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

    ListNode* helper(ListNode* &head, int count)
    {
        if(head->next == NULL)
        {
            return head;
        }

        ListNode* received = helper(head->next,count+1);
        if( count%2 != 0)
        {
            head->next = received->next;
            received->next = head;
            return received;
        }
        else
        {
            head ->next = received;
            return head;
        }

    }
    ListNode* swapPairs(ListNode* head) {
        if( head==NULL || head->next == NULL) return head;
        return helper(head,1);
    }
};