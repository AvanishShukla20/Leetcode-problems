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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* curr = head;
        while(head)
        {
            st.push(head);
            head = head->next;
        }

        int k = 1;
        int midnodeCount = st.size()/2;
        while(k <= midnodeCount)
        {
            ListNode* currNextStored = curr->next;
            ListNode* temp = st.top();
            st.pop();
            curr->next = temp;
            temp->next = currNextStored;
            curr = currNextStored;
            k++;
        }

        curr->next = NULL;

    }
};