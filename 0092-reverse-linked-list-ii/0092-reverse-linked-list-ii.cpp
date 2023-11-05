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

    ListNode* reverse(ListNode* head)
    {
        ListNode*  curr=head;
        ListNode* prev=NULL;
        ListNode* currNext;
        if(head->next==NULL)return head;
        while(curr)
        {
            currNext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=currNext;
            
        }
        return prev;

    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        int i=1;
        ListNode* rev=NULL;
        ListNode* revPrev=NULL;
        ListNode* revEnd=NULL;
        ListNode* revEndNext=NULL;

        ListNode* curr=head;
        while(curr and i<=right)
        {
            if(i<left)revPrev=curr;
            if(i==left)rev=curr;
            if(i==right)
            {
                revEnd=curr;
                revEndNext=curr->next;
            }
            curr=curr->next;
            i++;
        }
        revEnd->next=NULL;
        revEnd=reverse(rev);

        if(revPrev)
        {
            revPrev->next=revEnd;
        }
        else{
            head=revEnd;
        }
        rev->next=revEndNext;
        return head;
    }
};