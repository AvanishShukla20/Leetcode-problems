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
ListNode* middle(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* currNext;
        
        while(curr)
        {
            currNext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currNext;
        }
        return prev;
    }

    bool comparelist(ListNode* head1,ListNode* head2)
    {
        while(head1!=NULL and head2!=NULL)
        {
            if(head1->val!=head2->val)return false;   
            head1=head1->next;
            head2=head2->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL )return false;
        ListNode* current=head;
        ListNode* mid=middle(current);
        ListNode* rev=reverse(mid);
        return comparelist(head,rev);
    }
};