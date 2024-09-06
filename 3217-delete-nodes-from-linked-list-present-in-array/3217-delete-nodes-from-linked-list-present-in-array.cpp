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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> st;
        for(int it:nums)
            st.insert(it);
        ListNode* tmp=head;
        ListNode* prv=NULL;
        while(tmp)
        {  
         
            if(st.count(tmp->val)>0)
            {   ListNode* node=tmp;
             
                if(tmp==head||prv==NULL)
                {
                    head=tmp->next;  
                }
                else
                {
                  prv->next=tmp->next; 
                }
                tmp=tmp->next;
                node->next=NULL;
                delete node;      
            }
            else
            {
                prv=tmp;
                tmp=tmp->next;
            }
            
        }
        return head;    
    }
};