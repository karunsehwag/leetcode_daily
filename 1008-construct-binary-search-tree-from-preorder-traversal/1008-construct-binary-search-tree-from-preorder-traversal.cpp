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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder,0,preorder.size()-1);
    }
    TreeNode * build(vector<int>& preorder,int start,int end)
    {
        if(start>end)
            return nullptr;
        TreeNode* root= new TreeNode(preorder[start]);
        int right=start+1;
        while(right<=end&& preorder[right]<root->val)
            right++;
        root->left=build(preorder,start+1,right-1);
        root->right=build(preorder,right,end); 
        return root;
    }
};