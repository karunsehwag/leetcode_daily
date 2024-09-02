class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<bool> safe(n);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            safe[node]=true;
            for(auto neighbour:adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                    q.push(neighbour);
            }
        }
        vector<int> safenode;
        for(int i=0;i<n;i++)
        {
            if(safe[i])
                safenode.push_back(i);
        }
        return safenode;
        
    }
};