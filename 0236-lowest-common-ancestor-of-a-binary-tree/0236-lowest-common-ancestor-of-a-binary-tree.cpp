/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)
            return NULL;
        if(root->val==p->val||root->val==q->val)
            return root;
        TreeNode* leftv=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightv=lowestCommonAncestor(root->right,p,q);
        if(rightv&&leftv)
            return root;
        return (leftv!=NULL)?leftv : rightv;
        
    }
};