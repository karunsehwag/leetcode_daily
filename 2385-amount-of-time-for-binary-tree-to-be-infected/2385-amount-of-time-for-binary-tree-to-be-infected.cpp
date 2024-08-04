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
    TreeNode* findnode(TreeNode* root,int start)
    {
        if(root==NULL)
            return NULL;
        if(root->val==start)
            return root;
        TreeNode* left=findnode(root->left,start);
          if(left)
              return left;
        TreeNode* right=findnode(root->right,start);
         if(right)
             return right;
        
        return NULL;
    }
    void dfs(TreeNode* root,TreeNode* parent, unordered_map<TreeNode*,TreeNode*>& mp)
    {
        if(root==NULL)
            return ;
        if(!parent) parent=root;
        else mp[root]=parent;
        dfs(root->left,root,mp);
        dfs(root->right,root,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        
        TreeNode* target=findnode(root,start);
        unordered_map<TreeNode*,TreeNode*> mp;
        dfs(root,NULL,mp);
        queue<TreeNode*> q;
        set<TreeNode*> st;
        int cnt=-1;
        q.push(target);
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
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
                    st.insert(mp[node]);
                    q.push(mp[node]);
                }
                st.insert(node);
                
            }
            cnt++;
        }
        
        return cnt;
        
    }
};