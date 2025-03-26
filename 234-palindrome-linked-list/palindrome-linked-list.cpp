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
    ListNode* findMiddle(ListNode* head)
    {
        if(!head || !head->next) return head;
        ListNode* start = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL)
        {
            start = start->next;
            fast = fast->next->next;
        }

        return start;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr)
        {
            ListNode* currnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = currnext;
        }

        return prev;
    }
    bool compare(ListNode* head1, ListNode* head2)
    {
        // compare until anyone reaches NULL
        while(head1!=NULL and head2!=NULL)
        {
            if(head1->val!=head2->val)return false;   
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* midnode = findMiddle(head);
        ListNode* revHead = reverse(midnode);
        /*learn the struucture of linked list {1, 2, 3, 2, 1}
            AFTER REVERSE OPERATION 
            HEAD = 1->2->3->1->2->NULL
            and 
            REVHEAD = 1->2->3->NULL

            That means REVHEAD WILL BE A NEW LINKED LIST CREATED BY REVERSE FUNCTION
        */ 
        return compare(head, revHead);
    }
};