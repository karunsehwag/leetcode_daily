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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp1;
        ListNode* temp2;
        temp1=NULL;
        while(head)
        {
            temp2=head;
            head=head->next;
            temp2->next=temp1;
            temp1=temp2;
        }
        return temp1;
        
    }
};