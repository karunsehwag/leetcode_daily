class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string smallestString = "";
        queue<pair<TreeNode*, string>> nodeQueue;

        nodeQueue.push({root, string(1, root->val + 'a')});

        while (!nodeQueue.empty()) {

          
            auto[node, currentString] = nodeQueue.front();
            nodeQueue.pop();

        
            if (!node->left && !node->right) {

                if (smallestString.empty()) {
                    smallestString = currentString;
                } else {
                    smallestString = min(smallestString, currentString);
                }
            }

          
            if (node->left) {
                nodeQueue.push({node->left, char(node->left->val + 'a') + currentString});
            }

            if (node->right) {
                nodeQueue.push({node->right, char(node->right->val + 'a') + currentString});
            }
        }

        return smallestString;
    }
};