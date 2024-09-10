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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans=head;
        while(head&&head->next)
        {
            int n1=head->val;
            int n2=head->next->val;
            while(n1%n2)
            {
                int k=n1%n2;
                n1=n2;
                n2=k;
            }
            ListNode* node=new ListNode(n2);
            node->next=head->next;
            head->next=node;
            head=node->next;
        }
        return ans;  
    }
};