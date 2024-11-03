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
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root)
            return root;
        if(key<root->val)
        {
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val)
        {
            root->right=deleteNode(root->right,key);
            
        }
        else
        {
            if(!root->left&&!root->right)
            {
                delete root;
                return nullptr;
            }
            if(!root->left)
            {
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(!root->right)
            {
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            
            TreeNode* successor=findmin(root->right);
            root->val=successor->val;
            root->right=deleteNode(root->right,successor->val);
        }
        return root;
        
    }
    
    TreeNode* findmin(TreeNode* node)
    {
        while(node&&node->left)
            node=node->left;
        
        return node;
    }
};