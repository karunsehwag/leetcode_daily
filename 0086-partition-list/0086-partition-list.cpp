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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left= new ListNode(0);
        ListNode* right=new ListNode(0);
        ListNode* l=left;
        ListNode* r=right;
        while(head)
        {
            if(x>head->val)
            {
                l->next=head;
                l=l->next;
            }
            else
            {
                r->next=head;
                r=r->next;
            }
            
            head=head->next;
        }
        r->next=NULL;
        l->next=right->next;
        ListNode* newhead=left->next;
        delete left;
        delete right;
        
        return newhead;
    }
};