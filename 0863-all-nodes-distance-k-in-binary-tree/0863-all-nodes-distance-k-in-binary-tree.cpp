/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void dfs(TreeNode* root,TreeNode* parent)
    {
        if(!root) return;
        if(!parent) parent=root;
        else mp[root]=parent;
        dfs(root->left,root);
        dfs(root->right,root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
      
        
        dfs(root,NULL);
        queue<TreeNode*> q;
        set<TreeNode*> st;
        q.push(target);
        int cnt=0;
        vector<int> vec;
        while(!q.empty())
        {
            if(cnt>k) break;
           
            int size=q.size();
            for(int i=0;i<size;i++)
            {    TreeNode* node=q.front();
                 q.pop();
                if(node->left&&!st.count(node->left))
                {
                    st.insert(node->left);
                    q.push(node->left);
                }
                if(node->right&&!st.count(node->right))
                {
                     st.insert(node->right);
                    q.push(node->right);
                }
                if(mp.count(node)&&!st.count(mp[node]))
                {
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
                st.insert(node);
            if(cnt==k)
                vec.push_back(node->val);
        
                
            }
                cnt++;
        }
        return vec;
    }
};