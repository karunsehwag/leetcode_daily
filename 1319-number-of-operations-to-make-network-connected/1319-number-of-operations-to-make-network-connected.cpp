class Solution {
public:
    void dfs(int n,unordered_map<int,vector<int>>& mp,vector<int>& vis,int& edges)
    {
        vis[n]=1;
        for(int it:mp[n])
        {  
            if(vis[it]==0)
            {
                dfs(it,mp,vis,edges); 
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        int count=connections.size();
        vector<int> vis(n+1,0);
        unordered_map<int,vector<int>> mp;
        int edges=0;
        for(vector<int> it:connections)
        {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        int island=0;
        for(int i=0;i<n;i++)
        {  if(vis[i]==0)
              {   island++;
                 dfs(i,mp,vis,edges);
              }  
        }
            return island-1;
    }
};