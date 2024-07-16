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
 
    TreeNode* low(TreeNode* root, int s, int d) {
        if (root == nullptr)
            return nullptr;
        if (root->val == s || root->val == d)
            return root;
        TreeNode* left = low(root->left, s, d);
        TreeNode* right = low(root->right, s, d);
        if (left && right)
            return root;
        return left ? left : right;
    }


    bool getPath(TreeNode* root, int target, string& path) {
        if (root == nullptr)
            return false;
        if (root->val == target)
            return true;
        path += 'L';
        if (getPath(root->left, target, path))
            return true;
        path.pop_back(); 
        path += 'R';
        if (getPath(root->right, target, path))
            return true;
        path.pop_back(); 
        return false;
    }

    string getDirections(TreeNode* root, int s, int d) {
        TreeNode* lca = low(root, s, d);

        string pathToStart, pathToDest;
        getPath(lca, s, pathToStart);
        getPath(lca, d, pathToDest);

   
        for (char& c : pathToStart) {
            c = 'U';
        }

        return pathToStart + pathToDest;
    }
};
