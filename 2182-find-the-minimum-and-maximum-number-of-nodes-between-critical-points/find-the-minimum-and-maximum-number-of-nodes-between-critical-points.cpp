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
    bool iscritical(int pr, int curr, int next)
    {
        if((pr < curr && curr > next) || (pr > curr && curr < next)) return true;
        return false;

    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next || !head->next->next) return {-1, -1};

        ListNode* prev = NULL;
        int nodecnt = 0, criticalcnt = 0, firstone = 0, minans = 1e9, lastone, maxans = 0;
        while(head)
        {
            nodecnt++;
            if(prev == NULL || head->next == NULL)
            {
                prev = head;
                head = head->next;
            }
            else
            {
                if(iscritical(prev->val, head->val, head->next->val))
                {
                    if(criticalcnt == 0)
                    {
                        firstone = nodecnt;
                        lastone = nodecnt;
                        criticalcnt++ ;
                    }
                    else
                    {
                        minans = min(minans, (nodecnt - lastone));
                        lastone = nodecnt;
                    }
                    
                }
                prev = head;
                head = head->next;
            }
        }

        maxans = lastone - firstone;
        if(minans == 1e9) return {-1, -1};

        return {minans, maxans};
    }
};