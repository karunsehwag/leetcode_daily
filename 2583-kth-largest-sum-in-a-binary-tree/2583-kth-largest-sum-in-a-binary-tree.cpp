/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        vector<long long> vec;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {   long long val=0;
            int in=q.size();
            while(in>0)
            { TreeNode* ptr=q.front();
               q.pop();
               val+=ptr->val;
               if(ptr->left!=NULL)
                  q.push(ptr->left);
               if(ptr->right!=NULL)
                 q.push(ptr->right);
               in--;
            }
         vec.push_back(val);
        }
        sort(vec.rbegin(),vec.rend());
        if(k>vec.size())
            return -1;
        return vec[k-1];
    }
};