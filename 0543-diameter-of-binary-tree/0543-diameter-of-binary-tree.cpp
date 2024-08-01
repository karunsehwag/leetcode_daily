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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        rec(root,ans);
        return ans;
        
    }
    
    int rec(TreeNode* root,int& ans)
    {   if(root==NULL)
            return 0;
        
        int left=rec(root->left,ans);
        int right=rec(root->right,ans);
        
        ans=max(ans,right+left);
        
        return max(right,left)+1;
    }
};