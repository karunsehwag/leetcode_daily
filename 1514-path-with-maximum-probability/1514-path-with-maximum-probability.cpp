class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<double,int>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({succProb[i],edges[i][1]});
            mp[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        priority_queue<pair<double,int>> pq;
        vector<double> dis(n,0.0);
        pq.push({1.0,start_node});
        while(!pq.empty())
        {
            int node=pq.top().second;
            double wt=pq.top().first;
            pq.pop();
            for(auto it:mp[node])
            {
              int n1=it.second;
              double w=it.first;
              if(w*wt>dis[n1])
              {
                  dis[n1]=w*wt;
                  pq.push({dis[n1],n1});
              }
            }
        }
        
        return dis[end_node];
    }
};