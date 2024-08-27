class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<double> vec(n,0);
        vec[start_node]=1;
        for(int i=0;i<n-1;i++)
        {
            bool update=false;
            for(int j=0;j<edges.size();j++)
            {
               int u=edges[j][0];
               int v=edges[j][1];
               double path=succProb[j];
                if(vec[u]*path>vec[v])
                {
                    vec[v]=vec[u]*path;
                    update=true;
                }
                if(vec[v]*path>vec[u])
                {
                    vec[u]=vec[v]*path;
                    update=true;
                }
               
            }
            if(!update)
                break;
        }
        
        return vec[end_node];
        
        
    }
};