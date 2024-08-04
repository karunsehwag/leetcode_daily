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
    bool checkTree(TreeNode* root) {
        if(root==NULL)
            return 1;
        if(root->left==NULL)
        {
            if(root->val==root->right->val)
                return 1;
            else 
                return 0;
        }
        if(root->right==NULL)
        {
            if(root->val==root->left->val)
                return 1;
            else 
                return 0;
        }
        
        if(root->val==(root->left->val+root->right->val))
            return 1;
        return 0;
        
    }
};