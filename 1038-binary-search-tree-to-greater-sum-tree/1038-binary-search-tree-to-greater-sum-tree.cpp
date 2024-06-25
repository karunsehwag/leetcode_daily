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
    void inorder(vector<int>& vec,TreeNode* root)
    {
        if(root==NULL)
            return ;
        inorder(vec,root->left);
        vec.push_back(root->val);
        inorder(vec,root->right);
        
    }
     void inorderp(vector<int>& vec,TreeNode* root,int& ind)
    {
        if(root==NULL)
            return;
        inorderp(vec,root->left,ind);
        root->val=vec[ind];
        ind++;
        inorderp(vec,root->right,ind);
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> vec;
        inorder(vec,root);
        for(int i=vec.size()-2;i>=0;i--)
        {
            vec[i]=vec[i]+vec[i+1];
        }
        int k=0;
       inorderp(vec,root,k);
        return root;
        
    }
};