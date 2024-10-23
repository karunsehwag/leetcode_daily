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
    string small;
    void dp(TreeNode* root,string str)
    {
        if(root==NULL)
            return ;
        str=char(root->val+'a')+str;
        if(root->left==NULL&&root->right==NULL)
        {
           if(small==""||small>str)
               small=str;
        }
       dp(root->left,str),dp(root->right,str);
       return ;
    }
    string smallestFromLeaf(TreeNode* root) {
        dp(root,"");
        return small;
    }
};