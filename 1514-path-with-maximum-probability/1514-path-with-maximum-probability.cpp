class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<double,int>>> mp;
        for(int i=0;i<edges.size();i++)
        {
            mp[edges[i][0]].push_back({succProb[i],edges[i][1]});
            mp[edges[i][1]].push_back({succProb[i],edges[i][0]});
        }
        vector<double> dis(n,0.0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty())
        {
            int node=pq.top().second;
            double wt=pq.top().first;
            pq.pop();
             if (node == end_node) {
                return wt;
            }
            
            for(auto it:mp[node])
            {
                double w=it.first;
                int node1=it.second;
                if(w*wt>dis[node1])
                {
                    dis[node1]=w*wt;
                    pq.push({dis[node1],node1});
                }
            }
        }
        return 0;
    }
};