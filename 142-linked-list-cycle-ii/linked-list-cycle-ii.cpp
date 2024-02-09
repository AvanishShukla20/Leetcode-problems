/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next ) return NULL;

        ListNode* trav = head;
        set<ListNode*>s;

        while(trav != NULL)
        {
            if(s.find(trav) != s.end()) return trav;
            else s.insert(trav);
            trav = trav->next;
        }
        return NULL;
    }
};