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
    int moves=0;
    int distributeCoins(TreeNode* root) {
        moves=0;
        dfs(root);
        return moves;        
    }
    
private:
    int dfs(TreeNode* current)
    {
        if(current==nullptr) return 0;
        int left=dfs(current->left);
        int right=dfs(current->right);
        moves+=abs(left)+abs(right);
        return current->val-1+left+right;
    }
};