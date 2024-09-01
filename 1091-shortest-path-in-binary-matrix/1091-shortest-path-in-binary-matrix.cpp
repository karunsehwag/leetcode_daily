class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
        vector<vector<int>> vec(n,vector<int>(m,INT_MAX));
        vec[0][0]=1;
        pq.push({1,{0,0}});
        // Directions for 8 possible movements
        vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};
        while(!pq.empty())
        {
            auto it=pq.front();
            pq.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
             if (r == n-1 && c == m-1) return dis;
            for(int i=0;i<8;i++)
            {
                
                int newr=dx[i]+r;
                int newc=dy[i]+c;
                if(newr>=0&&newr<n&&newc>=0&&newc<m&&grid[newr][newc]==0&&dis+1<vec[newr][newc])
                {
                    vec[newr][newc]=dis+1;
                    pq.push({1+dis,{newr,newc}});
                }
                
            }
        }
        return -1;
        
    }
};