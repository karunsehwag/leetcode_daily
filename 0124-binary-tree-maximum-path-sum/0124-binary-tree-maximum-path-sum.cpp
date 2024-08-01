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
    int maxPathSum(TreeNode* root) {
        // Initialize the answer with the smallest integer value.
        int ans = INT_MIN;
        rec(root, ans);
        return ans;
    }
    
    // Function to compute the maximum path sum and update ans.
    int rec(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        
        // Recursively get the maximum sum of left and right subtrees.
        int left = max(rec(root->left, ans), 0); // Ignore negative paths
        int right = max(rec(root->right, ans), 0); // Ignore negative paths
        
        // Calculate the maximum path sum with the current node as the highest point.
        int currentMax = root->val + left + right;
      
        ans = max(ans, currentMax);
    
        return root->val + max(left, right);
    }
};
