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
    int ans=0;
    void dp(TreeNode* root,vector<int> vec)
    {   if(root==NULL)
           return;
        if(root->left==NULL&&root->right==NULL)
        {   vec[root->val]++;
            int count=0;
            for(int i=0;i<vec.size();i++)
            {
                if(vec[i]%2)
                    count++;
            }
           if(count<=1)
                 ans++;
            return ;
        }
        vec[root->val]++;
        dp(root->left,vec);
        dp(root->right,vec);  
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> vec(10,0);
        dp(root,vec);
        return ans;
    }
};