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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int i=1;
        int minv=INT_MAX,maxv=INT_MIN;
        int minvalue=-1,pr;
        int prv;
        prv=head->val;
        head=head->next;
        while(head&&head->next)
        {
            if(head->val>prv&&head->val>head->next->val)
            {
               
                if(minvalue==-1)
                {
                   minvalue=i;
                    pr=i;
                }
                else
                {
                minv=min(minv,i-pr);
                maxv=max(maxv,i-minvalue);
                }
                 pr=i;
                
            }
            else if(head->val<prv&&head->val<head->next->val)
            {
              
                 if(minvalue==-1)
                {
                  minvalue=i; 
                  pr=i;
                }
                else
                {
                minv=min(minv,i-pr);
                maxv=max(maxv,i-minvalue);
                }
                 pr=i;
                
            }
           
            i++;
            prv=head->val;
            head=head->next;    
        }
        vector<int> ans;
        if(maxv==INT_MIN&&minv==INT_MAX)
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(minv);
            ans.push_back(maxv);
        }
        return ans;
        
    }
};