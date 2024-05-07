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
    ListNode* doubleIt(ListNode* head) {
        vector<int> vec;
        int count=0;
        ListNode* node=head;
        
        while(node)
        {   vec.push_back(node->val);
            node=node->next;
        }
        
        if(vec[0]==0&&vec.size()==0)
        {ListNode* node=new ListNode(2*vec[0]);
          return node;
        }
        
        reverse(vec.begin(),vec.end());
        int i=0;
        node=NULL;
        
        
        while(vec.size()>i)
        {  
            ListNode* start=new ListNode();
            start->next=node;
            count=count+vec[i]*2;
            cout<<count<<" ";
            start->val=count%10;
            count=count/10;
            node=start;
             i++;
        }
        if(count!=0)
        {  
            ListNode* start=new ListNode(count);
            start->next=node;
            node=start;
             
        }
            
        return node;
        
    }
};