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
    ListNode* mergeNodes(ListNode* head) {
        
       
        head=head->next;
        ListNode* temp=head;
         ListNode* temp1=head;
        int count=0;
        while(temp)
        { 
          if(temp->val!=0&&count!=0)
          {temp1->val+=temp->val;} 
            else if(temp->val==0)
            {
                temp1->next=temp->next;
                temp1=temp1->next;
                count=-1;
            }
            count++;
            temp=temp->next;
        }
        
        return head;
        
    }
};