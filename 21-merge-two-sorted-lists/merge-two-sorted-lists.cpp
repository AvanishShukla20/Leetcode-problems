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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        /* MY CODE (Long lines)
        part 1 -> 
        if(list1 == NULL and list2 == NULL)
        {
            return NULL;
        }
        else if(list1 != NULL and list2 == NULL)
        {
            return list1;
        }
        else if (list1 == NULL and list2 != NULL)
        {
            return list2;
        }
        */

        //updated base case 

        if(list1 == NULL)
        {
            return list2;
        }
        if(list2 == NULL)
        {
            return list1;
        }

        /* Your Implementation (Wrong) 
        ListNode* receivedNode = mergeTwoLists(list1->next, list2->next);

        if(list1->val <= list2->val)
        {
            list1->next = list2;
            list2->next = receivedNode;
            return list1;
        }
        else
        {
            list2->next = list1;
            list1->next = receivedNode;
            return list2;
        }*/

        //correct ->

        if(list1 ->val <= list2 ->val)
        {
            ListNode* rec1 = mergeTwoLists(list1 -> next, list2);
            list1->next = rec1;
            return list1;
        }
        else
        {
            ListNode* rec2 = mergeTwoLists(list1, list2 -> next);
            list2 ->next = rec2;
            return list2;
        }
    }
};