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
    int solve(TreeNode* root, int maxv,int minv)
    {
        if(!root) return 0;
        int val=root->val;
        int noder=max(abs(val-maxv),abs(val-minv));
        int leftr=solve(root->left,max(val,maxv),min(val,minv));
        int rightr=solve(root->right,max(val,maxv),min(val,minv));
        return max({noder,leftr,rightr});
    }
    int maxAncestorDiff(TreeNode* root) {
        return solve(root,root->val,root->val);
        
    }
};