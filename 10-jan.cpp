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
    void rec(TreeNode* r, unordered_map<int, vector<int>>& mp)
    {
        if(r==NULL)
          return;
        if(r->left)
        {
            mp[r->val].push_back(r->left->val); 
            mp[r->left->val].push_back(r->val);
        }
        if(r->right)
        {
            mp[r->val].push_back(r->right->val);
            mp[r->right->val].push_back(r->val);
        }
        rec(r->left,mp);
        rec(r->right,mp);
        return;
    }
    int amountOfTime(TreeNode* root, int start)
    {
        unordered_map<int,vector<int>> mp;
        rec(root,mp);
        unordered_map<int,int> vec;
        unordered_map<int,int> lev;
        vec[start]=1;
        lev[start]=0;
        queue<int> q;
        q.push(start);
        int count=0;
        while(!q.empty())
        {   int k=q.front(); 
            q.pop();
            for(auto it: mp[k])
            {  
                if(!vec[it])
                {
                   q.push(it);
                   vec[it]=vec[k]+1;
                   lev[it]=lev[k]+1;
                   count=max(lev[it],count);
                   
                }
               
            }
        }

       return count; 
    }
};