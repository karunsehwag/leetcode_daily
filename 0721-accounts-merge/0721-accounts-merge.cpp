class Solution {
public:
    class Disjointset
    {
        vector<int> parent,size;
        public:
        Disjointset(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++)
            {parent[i]=i;}
        }
        int findupar(int node)
        {
            if(parent[node]==node)
                return node;
            return parent[node]=findupar(parent[node]);
        }
        void unionfind(int u,int v)
        {
            int u_u=findupar(u);
            int u_v=findupar(v);
            if(u_u==u_v)
                return;
            if(size[u_u]>size[u_v])
            {
                parent[u_v]=u_u;
                size[u_u]+=size[u_v];
            }
            else
            {
                parent[u_u]=u_v;
                size[u_v]+=size[u_u]; 
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n=accounts.size();
        unordered_map<string,int> mp;
        Disjointset Ds(n);
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
                    Ds.unionfind(i,mp[accounts[i][j]]);
                }
                
            }
        }
            vector<string> mergedmail[n];
            
            for(auto it:mp)
            {
                string node=it.first;
                int val=Ds.findupar(it.second);
                mergedmail[val].push_back(node);
                
            }
            vector<vector<string>> ans;
            for(int i=0;i<n;i++)
            {
                if(mergedmail[i].size()==0) continue;
                sort(mergedmail[i].begin(),mergedmail[i].end());
                vector<string> temp;
                temp.push_back(accounts[i][0]);
                for(auto it:mergedmail[i])
                {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
            
            sort(ans.begin(),ans.end());        
         return ans;
        
    }
};