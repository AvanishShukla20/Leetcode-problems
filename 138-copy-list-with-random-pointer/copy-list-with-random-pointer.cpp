/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;

        Node* start = head;
        map<Node* , Node*> mpp;

        Node* newhead = new Node(start->val);
        mpp[start] = newhead;

        Node* t = newhead;
        while(start != NULL)
        {
            if(start->next == NULL) t->next = NULL;
            else
            {
                Node* p = new Node(start->next->val);
                t->next = p;
                mpp[start->next] = p;
            }
            t=t->next;
            start = start->next;
        }

        start = head;
        t = newhead;

        while(start != NULL)
        {
            if(start->random == NULL) t->random = NULL;
            else t->random = mpp[start->random];
            t=t->next;
            start = start->next;
        }

        return newhead;
    }
};