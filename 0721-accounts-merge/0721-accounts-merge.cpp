class Disjointset
{
    vector<int> parent,size;
    public:
    Disjointset(int n)
    {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findpar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findpar(parent[node]);
    }
    void unionsize(int u,int v)
    {
        int u_u=findpar(u);
        int v_v=findpar(v);
        
        if(u_u==v_v)
            return;
        if(size[u_u]>size[v_v])
        {
            parent[v_v]=u_u;
            size[u_u]+=size[v_v];
        }else
        {
            parent[u_u]=v_v;
            size[v_v]+=size[u_u];
        }
    }
    
    int getsize(int node)
    {
        return size[findpar(node)];
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        vector<vector<string>> ans;
        unordered_map<string,int> mp;
        int n=accounts.size();
        Disjointset ds(n);
        for(int i=0;i<accounts.size();i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(mp.find(accounts[i][j])==mp.end())
                {
                    mp[accounts[i][j]]=i;
                }
                else
                {
                    ds.unionsize(i,mp[accounts[i][j]]);
                }
            }
        }
        vector<string> vec[accounts.size()];
        for(auto it:mp)
        {
            string node=it.first;
            int val=ds.findpar(it.second);
            vec[val].push_back(node);
        }
        for(int i=0;i<accounts.size();i++)
        {
            if(vec[i].size()==0)
                continue;
            sort(vec[i].begin(),vec[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(string str:vec[i])
            {
                temp.push_back(str);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};