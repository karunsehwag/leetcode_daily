class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adjacenecyList(n);
        vector<vector<int>> shortestpath(n,vector<int>(n,INT_MAX));
        
        for(int i=0;i<n;i++)
        {
            shortestpath[i][i]=0;
        }
        for(auto& edge:edges)
        {
          adjacenecyList[edge[0]].push_back({edge[1],edge[2]});
          adjacenecyList[edge[1]].push_back({edge[0],edge[2]});
            
        }
        
        for(int i=0;i<n;i++)
        {
            dijkstra(n,adjacenecyList,shortestpath[i],i);
        }
        return getcity(n,shortestpath,distanceThreshold);
        
    }
    
    void dijkstra(int n,vector<vector<pair<int,int>>>& adj,vector<int>& shortestpath,int source)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        fill(shortestpath.begin(),shortestpath.end(),INT_MAX);
        shortestpath[source]=0;
        while(!pq.empty())
        {
            auto [currentDistance,currentcity]=pq.top();
            pq.pop();
            if(currentDistance> shortestpath[currentcity])
            {
                continue;
            }
            
            for(auto& [neighbor,edgeweight]:adj[currentcity])
            {
                if(shortestpath[neighbor]>currentDistance+edgeweight)
                {
                    shortestpath[neighbor]=currentDistance+edgeweight;
                    pq.push({shortestpath[neighbor],neighbor});
                }
            }
        }
    }
    int getcity(int n,vector<vector<int>>& vec,int dis)
    {
        int city=-1;
        int fewest=n;
        
        for(int i=0;i<n;i++)
        {
            int reach=0;
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                if(vec[i][j]<=dis)
                    reach++;
            }
            if(reach<=fewest)
            {
               fewest=reach;
               city=i;
            }
        }
        
        return city;
        
    }
    
};