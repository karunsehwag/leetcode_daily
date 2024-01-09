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
    void  rec(TreeNode* r,vector<int>&vec)
    {    if(r==NULL)
            return ;
        if(r->left==NULL&& r->right==NULL)
           {
               vec.push_back(r->val);
               return ;
           }
           rec(r->left,vec);
           rec(r->right,vec);
           return ;

    }
   
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> v1,v2;
        rec(root1,v1);
        rec(root2 ,v2);
        if(v1.size()!=v2.size())
           return 0;
        for(int i=0;i<v1.size();i++)
        {
            if(v1[i]!=v2[i])
               return 0;
        }
        return 1;   
    }
};