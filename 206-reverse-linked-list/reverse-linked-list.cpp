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
    ListNode* reverseLogic(ListNode* head, ListNode* newHead) {
        if(head->next==NULL)
        {
            head->next = newHead;
            return head;
        }
        ListNode* getNode = reverseLogic(head->next,head);
        head ->next = newHead;
        newHead->next = NULL;
        return getNode;

    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        //it is very important to realise WHY (head,head) is passed as argument 
        return reverseLogic(head,head);

        // earlier you were passing (head->next,NULL) here 
    }
};