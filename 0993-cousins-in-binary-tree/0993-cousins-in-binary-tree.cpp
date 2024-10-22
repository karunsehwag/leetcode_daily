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
    int xd,xp,yd,yp;
    void helper(TreeNode* root,int x,int y,int parent,int depth)
    {
        if(root!=NULL)
        {
        
        if(root->val==x)
        {
            xd=depth;
            xp=parent;
        }
        if(root->val==y)
        {
            yd=depth;
            yp=parent;
        }
        depth++;
        parent=root->val;
        helper(root->left,x,y,parent,depth);
        helper(root->right,x,y,parent,depth);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        helper(root,x,y,0,1);
        if(xd==yd&&xp!=yp)
            return true;
        return false;
    }
};