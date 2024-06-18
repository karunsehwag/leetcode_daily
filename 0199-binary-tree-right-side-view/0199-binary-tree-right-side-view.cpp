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
    void tree(TreeNode* root,vector<int>& vec,int level,int* maxlevel)
    {
        if(root==NULL)
            return ;
        if(level>*maxlevel)
        {
            vec.push_back(root->val);
            *maxlevel=level;
            
        }
        tree(root->right,vec,level+1,maxlevel);
        tree(root->left,vec,level+1,maxlevel);
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        int maxlevel=0;
        tree(root,vec,1,&maxlevel);
        return vec;
        
    }
};