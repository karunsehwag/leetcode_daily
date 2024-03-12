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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front =new ListNode(0,head);
        ListNode* cur=front;
        int prefixsum=0;
        unordered_map<int,ListNode*> prefixsumtonode;
        while(cur!=nullptr)
        {
            prefixsum+=cur->val;
            if(prefixsumtonode.find(prefixsum)!=prefixsumtonode.end())
            {
                ListNode* prev=prefixsumtonode[prefixsum];
                cur=prev->next;
                int p=prefixsum+cur->val;
                while(p!=prefixsum)
                {
                    prefixsumtonode.erase(p);
                    cur=cur->next;
                    p+=cur->val;
                }
                prev->next=cur->next;
            }
            else
            {
                prefixsumtonode[prefixsum]=cur;
            }
            cur=cur->next;
        }
        return front->next;
    }
};