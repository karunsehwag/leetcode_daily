class Solution {
public:
    vector<int> levelSum;

    void calculateLevelSum(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        if (depth >= levelSum.size()) {
            levelSum.push_back(node->val);
        } else {
            levelSum[depth] += node->val;
        }

        calculateLevelSum(node->left, depth + 1);
        calculateLevelSum(node->right, depth + 1);
    }

    void updateNodeValues(TreeNode* node, int depth) {
        if (node == nullptr) {
            return;
        }

        if (node->left && node->right) {
            int childrenSum = node->left->val + node->right->val;
            node->left->val = levelSum[depth] - childrenSum;
            node->right->val = levelSum[depth] - childrenSum;
        } else if (node->left) {
            node->left->val = levelSum[depth] - node->left->val;
        } else if (node->right) {
            node->right->val = levelSum[depth] - node->right->val;
        }

        updateNodeValues(node->left, depth + 1);
        updateNodeValues(node->right, depth + 1);
    }

    TreeNode* replaceValueInTree(TreeNode* root) {
        calculateLevelSum(root, 0);
        root->val = levelSum[0] - root->val;
        updateNodeValues(root, 1);
        return root;
    }
};
