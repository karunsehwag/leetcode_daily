class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src==dst)
            return 0;
        queue<pair<int,pair<int,int>>> pq;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(vector<int> it: flights)
        {
            adj[it[0]].push_back({it[2],it[1]});
        }
        pq.push({0,{0,src}});
        vector<int> dis(n,INT_MAX),vec(n,0);
        dis[src]=0;
        int ans=INT_MAX;
        while(!pq.empty())
        {   auto ptr=pq.front();
            int stops=ptr.first;
            int cost=ptr.second.first;
            int node=ptr.second.second;
            pq.pop();
             if (stops > k) {
                continue;
            }

            for(auto it:adj[node])
            {
                int n=it.second;
                int w=it.first;
                if(w+cost<dis[n])
                { 
                    dis[n]=w+cost;
                    pq.push({stops + 1, {cost + w, n}});
                        
                }
            }

            
        }
       return dis[dst] == INT_MAX ? -1 : dis[dst];
        
    }
};