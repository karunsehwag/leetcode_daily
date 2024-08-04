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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        using ull = unsigned long long; // alias for unsigned long long
        std::queue<std::pair<TreeNode*, ull>> q;
        int ans = 0;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            ull minv = q.front().second;
            ull start = 0, last = 0;

            for (int i = 0; i < size; ++i) {
                ull val = q.front().second - minv;
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) start = val;
                if (i == size - 1) last = val;

                if (node->left)
                    q.push({node->left, val * 2});
                if (node->right)
                    q.push({node->right, val * 2 + 1});
            }

            ans = std::max(ans, int(last + 1 - start));
        }

        return ans;
    }
};
