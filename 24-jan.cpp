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
    int sum = 0;

    int ch(const unordered_map<int, int>& mp) {
        int c = 0;
        for (const auto& pair : mp) {
            if (pair.second % 2) {
                c++;
            }
        }
        return c <= 1 ? 1 : 0;
    }

    void rec(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr)
            return;

        mp[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            sum += ch(mp);
            mp[root->val]--; // Backtrack to the previous state
            return;
        }

        rec(root->left, mp);
        rec(root->right, mp);

        mp[root->val]--; // Backtrack to the previous state
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        unordered_map<int, int> mp;
        rec(root, mp);
        return sum;
    }
};