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
    void dfs(TreeNode* root,TreeNode* parent,unordered_map<TreeNode*,TreeNode*>& mp)
    {
        
        if(root==NULL)
            return;
        if(!parent) parent=root;
        else mp[root]=parent;
        
        dfs(root->left,root,mp);
        dfs(root->right,root,mp);
        return;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        unordered_map<TreeNode*,TreeNode*> mp;
        dfs(root,NULL,mp);
        queue<TreeNode*> q;
        q.push(target);
        set<TreeNode*> st;
        int cnt=0;
        vector<int> ans;
        while(!q.empty())
        {
            if(cnt>k)
                break;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left&&!st.count(node->left))
                {
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right&&!st.count(node->right))
                {
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mp.count(node)&&!st.count(mp[node]))
                {
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
                st.insert(node);
                if(cnt==k)
                    ans.push_back(node->val);
                
            }
            cnt++;
            
            
        }
        return ans;
        
    }
};