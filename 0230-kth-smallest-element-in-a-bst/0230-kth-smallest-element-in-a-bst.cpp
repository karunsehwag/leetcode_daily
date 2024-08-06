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
    void rec(TreeNode* root,int k,int& cnt,int& ans)
    {
        if(root==NULL)
            return;
        rec(root->left,k,cnt,ans);
         cnt++;
        if(k==cnt)
        {
            ans=root->val;
            return ;
        }
        rec(root->right,k,cnt,ans);
        
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        
        int cnt =0;
        int ans=0;
        rec(root,k,cnt,ans);
        return ans;
    }
};