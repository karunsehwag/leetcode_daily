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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        int z=1;
        vector<vector<int>> ans;
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        bool leftToRight = true;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            deque<int> vec;
            
            for(int i=0;i<size;i++)
            { TreeNode* t=q.front();
              q.pop();
              if(z)
                  vec.push_back(t->val);
             else 
                 vec.push_front(t->val);
              if(t->left!=NULL) q.push(t->left);
              if(t->right!=NULL) q.push(t->right); 
              
            }
           
            ans.push_back(vector<int>(vec.begin(),vec.end()));
            z=1-z;
        }
        return ans;
        
    }
};