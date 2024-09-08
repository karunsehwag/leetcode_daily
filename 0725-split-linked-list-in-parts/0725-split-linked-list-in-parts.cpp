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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* tmp=head;
        while(tmp)
        {
            size++;
            tmp=tmp->next;
        }
        int val=size%k;
        size=size/k;
        vector<ListNode*> ans;
        tmp=head;
        int count=0;
        while(tmp)
        {   if(count==0)
              {ans.push_back(tmp);
               if(val>0)
                   val--;
               else 
                   count++;
               }
            if(count>=size)
            {
                count=0;
                ListNode* node=tmp;
                tmp=tmp->next;
                node->next=NULL;
            }
         else
         {
             count++;
             tmp=tmp->next;
         }
        }
        while(k>ans.size())
            ans.push_back(NULL);   
        return ans;  
    }
};