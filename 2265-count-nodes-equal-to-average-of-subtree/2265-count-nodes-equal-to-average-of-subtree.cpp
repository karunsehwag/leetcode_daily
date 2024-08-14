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
    pair<int,int> rec(TreeNode* root,int& count)
    {
        if(root==NULL)
            return {0,0};
        auto left=rec(root->left,count);
        auto right=rec(root->right,count);
        int sum=left.first+right.first+root->val;
        int div=left.second+right.second+1;
        if(sum/div==root->val)
            count++;
        return {sum,div};
        
    }
    int averageOfSubtree(TreeNode* root) {
        
        int count=0;
        rec(root,count);
        return count;
        
    }
};