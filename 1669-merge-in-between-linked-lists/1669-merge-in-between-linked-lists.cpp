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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) 
    {
        ListNode* head=list1;
        ListNode* temp=list1;
        ListNode* ans=list1;
      
        a--;
        while(a>0)
        {
            a--;
          
            ans=ans->next;
            
        }
        b++;
        while(b>0)
        {
            b--;
            temp=temp->next;
        }
        ans->next=list2;
        while(ans->next!=NULL)
        {
            ans=ans->next;
        }
        ans->next=temp;
        return head;
        
    }
};