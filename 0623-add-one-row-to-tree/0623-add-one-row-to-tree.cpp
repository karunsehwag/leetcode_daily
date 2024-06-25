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
    void track(TreeNode* root, int val, int depth)
    {     if(root==NULL) return ;
          if(depth==1)
          {
              TreeNode* ptr1 = new TreeNode(val);
              TreeNode* ptr2 = new TreeNode(val);
              ptr1->left=root->left;
              root->left=ptr1;
              ptr2->right=root->right;
              root->right=ptr2;
              return ;
          }
        track(root->left,val,depth-1);
        track(root->right,val,depth-1);
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        track(root,val,depth-1);
      return root;
         
        
    }
};