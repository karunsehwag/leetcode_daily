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
    bool helper(TreeNode* root,long long int low,long long int high)
    {
        if(!root)
            return true;
        if(root->val<=low||root->val>=high)
            return false;    
        return helper(root->left,low,root->val)&&helper(root->right,root->val,high);
    }
    bool isValidBST(TreeNode* root) {
         return helper(root, numeric_limits<long long>::min(),numeric_limits<long long>::max());
    }
};