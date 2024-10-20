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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(ListNode* ptr:lists)
        {
            while(ptr!=NULL)
            {
                pq.push(ptr->val);
                ptr=ptr->next;
            }
        }
        ListNode* head=NULL;
        ListNode* ptr=NULL;
        while(!pq.empty())
        {
            ListNode* node= new ListNode(pq.top());
            if(head==NULL)
            {head=node;
             ptr=node;
            }
            else
            {
            ptr->next=node;
            ptr=ptr->next;
            }
            pq.pop();
        }
        
        return head;
    }
};