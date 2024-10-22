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
    vector<int> vec;
    void helper(TreeNode* root,int x)
    {
        if(root==NULL)
            return;
        if(x>=vec.size())
            vec.push_back(root->val);
        else
        {
            vec[x]+=root->val;
        }
        x++;
        helper(root->left,x);
        helper(root->right,x);
    }
    void helper2(TreeNode* root,int x)
    {
        if(root==NULL)
            return;
        // cout<<vec[x]<<"  "<<endl;
        int stor=0;
        if(root->left)
        {   stor=root->left->val;
            root->left->val=vec[x]-root->left->val;
            if(root->right)
               root->left->val=root->left->val-root->right->val;
        }
        if(root->right)
        { 
          root->right->val=vec[x]-root->right->val;
          if(root->left)
             root->right->val=root->right->val-stor;
        }
        x++;
        helper2(root->left,x);
        helper2(root->right,x);
        
    }
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        TreeNode* head=root;
        helper(root,0);
        root->val=vec[0]-root->val;
        helper2(root,1);
        return root;
        
    }
};