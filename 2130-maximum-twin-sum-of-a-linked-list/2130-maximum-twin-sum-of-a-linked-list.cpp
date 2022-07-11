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
    
     ListNode* reverse(ListNode *head)
     {  ListNode *prev = NULL,*cur = head,*next =NULL;
       while(cur)
       {
           next = cur->next;
           cur->next=prev;
           prev = cur;
           cur=next;
          
       }
      
         return prev;
     }
    int pairSum(ListNode* head) {
        if(head->next->next == NULL){return head->val + head->next->val;}
        ListNode* ans = new ListNode;
        ans->next = head;
        ListNode* slow = ans;
        ListNode* fast = ans;
         while(fast and fast->next)
         { 
              slow = slow->next;
              fast = fast->next->next;
         }
      ListNode *head2 = slow->next;
        slow->next = NULL;
        ListNode* head3= reverse(head);
        int mini = INT_MIN;
        while(head3 and head2)
        {   
            mini = max(mini,head2->val+head3->val);
            
            head2 = head2->next;
            head3 = head3->next;
        }
        return mini;
    }
};