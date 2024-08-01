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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> vec;
            for(int i=0;i<size;i++)
            {
              TreeNode* point=q.front();
                q.pop();
                if(point->left!=NULL) q.push(point->left);
                if(point->right!=NULL) q.push(point->right);
                vec.push_back(point->val);
            }
            ans.push_back(vec);
        }
        return ans;
        
    }
};