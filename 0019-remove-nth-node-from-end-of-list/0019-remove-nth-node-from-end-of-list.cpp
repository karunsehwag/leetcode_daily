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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int m=0;
        ListNode* temp=head;
        while(temp)
        {
            temp=temp->next;
            m++;
        }
        if(m==1&&n==1)
          return NULL;
        if(m==n)
          return head->next;  
          
        m=m-n-1;
        temp=head;
        ListNode* temp1;
        while(m>0)
        {
         temp=temp->next;
         m--;
        }
        if(temp->next)
        {temp1=temp->next;
        temp->next=temp1->next;}
       
    
        return head;
        
    }
};