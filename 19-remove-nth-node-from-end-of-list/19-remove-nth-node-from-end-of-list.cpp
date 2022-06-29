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
     int count(ListNode * root)
     {
         int k = 0;
          while(root)
          {
              ++k;
              root = root->next;
          }
          return k;
     }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         int k = count(head)-n+1;
         cout<<k<<"KK";
        
         if (k ==1)
         {
             head = head->next;
              return head;
         }
        int g = k-1;
        ListNode *ans = head;
        ListNode * prev  = head;
         while(--g)
         {
             prev = prev->next;
         }
        cout<<prev->val<<"val";
         while(--k)
         {
             head =  head->next;
         }
        prev->next = head->next;
         return ans;
    }
};