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
    int widthOfBinaryTree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        using ull = unsigned long long; // alias for unsigned long long
        std::queue<std::pair<TreeNode*, ull>> q;
        int ans=0;
        q.push({root,0});
        while(!q.empty())
        {
            ull minv=q.front().second;
            ull size=q.size();
            ull start=0,last=0;
            for(int i=0;i<size;i++)
            {
                ull val=q.front().second-minv;
                TreeNode* tree=q.front().first;
                q.pop();
                if(i==0) start=val;
                if(i==size-1) last=val;
                if(tree->left)
                    q.push({tree->left,val*2});
                if(tree->right)
                    q.push({tree->right,val*2+1});
            }
            ans=max(ans,int(last+1-start));
        }
        return ans;
    }
};