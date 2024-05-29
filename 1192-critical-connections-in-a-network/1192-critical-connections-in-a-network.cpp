class Solution {
public:
    int timer=1;
void dfs(int node, int parent, vector<vector<int>>& vec, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<vector<int>>& bridges) {
    vis[node] = 1;
    tin[node] = low[node] = timer++;

    for (auto x : vec[node]) {
        if (x == parent)
            continue;
        if (!vis[x]) {
            dfs(x, node, vec, vis, tin, low, bridges);
            low[node] = min(low[node], low[x]);
            if (low[x] > tin[node]) {
                bridges.push_back({node, x});
            }}
                else
                {
                    low[node]=min(low[node],low[x]);
                }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        vector<vector<int>> vec(n);
        vector<int> vis(n,0);
        vector<int> tin(n,0);
        vector<int> low(n,0);
        for(vector<int> x:con)
        {
            vec[x[0]].push_back(x[1]);
            vec[x[1]].push_back(x[0]);    
        }
        vector<vector<int>> bridges;
        dfs(0,-1,vec,vis,tin,low,bridges);
        return bridges;
    }
};