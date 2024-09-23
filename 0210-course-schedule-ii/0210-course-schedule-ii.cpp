class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        vector<int> indegree(numCourses,0);
       
        for(auto it:prerequisites)
        {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        vector<int> ans;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        if(ans.size()==numCourses)
            return ans;
        ans.clear();
        return ans;
    }
};