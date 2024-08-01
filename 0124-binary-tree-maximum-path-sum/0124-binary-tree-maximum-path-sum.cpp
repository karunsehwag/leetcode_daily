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
    int maxPathSum(TreeNode* root) {
        
        int ans=INT_MIN;
        rec(root,ans);
        return ans;
    }
    
    int rec(TreeNode* root,int& ans)
    {
        if(root==NULL)
            return 0;
        
        int left=max(rec(root->left,ans),0);
        int right=max(rec(root->right,ans),0);
        ans=max(ans,(left+right+root->val));
        
        return max(left,right)+root->val;
    }
};