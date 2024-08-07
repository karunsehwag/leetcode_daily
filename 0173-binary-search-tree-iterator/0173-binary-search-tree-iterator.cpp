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
class BSTIterator {
private: stack<TreeNode*> mystack;
public:
    BSTIterator(TreeNode* root) {
        pushall(root);
        
        
    }
    
    int next() {
        TreeNode* node=mystack.top();
        mystack.pop();
        pushall(node->right);
        return node->val;
        
       
    }
    
    bool hasNext() {
        
         return !mystack.empty();
    }
    
    void pushall(TreeNode* node)
    {
        for(;node!=NULL;mystack.push(node),node=node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */