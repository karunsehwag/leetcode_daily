class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int,vector<int>> mp;
       
        for(int i=0;i<n;i++)
        {
            mp[i].push_back(i+1);
        }
        for(auto it:queries)
        {    vector<int> vis(n,0);
            int stor=INT_MAX;
            mp[it[0]].push_back(it[1]);
            int count=INT_MAX;
            queue<pair<int,int>> q;
            q.push({0,0});
            vis[0]=1;
            while(!q.empty())
            {
                int val=q.front().first;
                int count=q.front().second;
                q.pop();
                if(val==n-1)
                {
                    stor=min(stor,count);
                    continue;
                }
                for(auto ptr:mp[val])
                {   if(!vis[ptr])
                      { 
                    vis[ptr]=1;
                    q.push({ptr,count+1});}
                }  
           
            }
         ans.push_back(stor);
        }
        
        
        return ans;     
    }
};