/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    
    string rec(TreeNode* root,string& ans)
    {
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            
                int size=q.size();
            
                for(int i=0;i<size;i++)
                {
                    TreeNode* node=q.front();
                    q.pop(); 
                    if(node==NULL)
                        ans+="#,";
                    else
                    {
                        ans+=to_string(node->val)+",";
                        q.push(node->left);
                        q.push(node->right);
                    
                    }
                    
                }
            
            
        } 
        return ans;
            
            
            
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans="";
        if(root==NULL)
            return ans;
        return rec(root,ans);
               
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty())
            return nullptr;
        
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            getline(s,str,',');
            if(str!="#")
            {
                TreeNode* leftnode=new TreeNode(stoi(str));
                node->left=leftnode;
                q.push(leftnode);
            }
            getline(s,str,',');
            if(str!="#")
            {
                TreeNode* rightnode=new TreeNode(stoi(str));
                node->right=rightnode;
                q.push(rightnode);
            }
        }
        
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));