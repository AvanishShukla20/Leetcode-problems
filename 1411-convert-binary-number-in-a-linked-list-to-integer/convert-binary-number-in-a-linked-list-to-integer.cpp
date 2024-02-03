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
    int binToInt(string s)
    {
        int ans = 0, n = s.size();
        for(int i=0; i <n ; i++)
        {
            int dig = s[n - i - 1] -'0';
            ans |= (dig<<i);
        }
        return ans;
    }
    int getDecimalValue(ListNode* head) {
      string ans ="";
      ListNode* temp = head;
      while(temp != NULL)
      {
        ans += temp -> val +'0';
        temp = temp->next; 
      }

      cout<<ans<<endl;
      int res = binToInt(ans);
      return res;
    }
};