class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> it:edges)
        {
            adj[it[0]].push_back({it[2],it[1]});
            adj[it[1]].push_back({it[2],it[0]});
        }
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
            dis[i][i]=0;
        for(int i=0;i<n;i++)
             dijkstra(dis[i],adj,n,i);
        
       
         int ans=0;
         int few=INT_MAX;
        for(int i=0;i<n;i++)
        {   int count=0;
            for(int j=0;j<n;j++)
            {
                if(dis[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
         
         if(few>=count)
         {
             few=count;
             ans=i;
         }
        }
        
      return ans;  
        
    }
    
    void dijkstra(vector<int>& dis,unordered_map<int,vector<pair<int,int>>>& adj,int n,int i)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,i});
        dis[i]=0;
        while(!pq.empty())
        {
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for(auto it:adj[node])
            {
                int n=it.second;
                int w=it.first;
                if(w+wt<dis[n])
                {
                    dis[n]=w+wt;
                    pq.push({dis[n],n});
                }
            }
        }
    }
    
    
};