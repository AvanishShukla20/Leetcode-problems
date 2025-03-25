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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* getkthNode(ListNode* h, int k)
    {
        ListNode* t = h;
        while(k > 1 && t)
        {
            t = t->next;
            k--;
        }

        return t;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevNode = &dummy;
        ListNode* temp = head;

        while(temp)
        {
            ListNode* kthNode = getkthNode(temp, k);
            if (!kthNode) break;  // Stop if less than k nodes remain

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL; // Temporarily break the list

            // Reverse the k nodes
            ListNode* s = reverseList(temp);
            prevNode->next = s;

            // Move prevNode and temp to continue processing
            temp->next = nextNode;
            prevNode = temp;
            temp = nextNode;
        }

        return dummy.next;
    }
};