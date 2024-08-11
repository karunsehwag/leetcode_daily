class Solution {
public:
    int g=0;
    int minDays(vector<vector<int>>& grid) {
        if(count(grid)!=1)
            return 0;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]==1)
                {   grid[i][j]=0;
                    if(count(grid)!=1)
                        return 1;
                 grid[i][j]=1;
                    
                }
            }
        }
        return 2;
        
    }
    
    int count(vector<vector<int>>& grid)
    {
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        int island=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1&&!vis[i][j])
                {
                    bfs(i,j,grid,vis);
                    island++;
                }
            }
        }
        
            
        return island;
    }
    
    void bfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>>& vis)
    {
        vector<int> direction = {-1, 0, 1, 0, -1}; 
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=true;
        while(!q.empty())
        {
            
            auto [x,y]=q.front();
            q.pop();
            for(int d=0;d<4;d++)
            {
                int r=x+direction[d];
                int c=y+direction[d+1];
                if(r>=0&&r<grid.size()&&c>=0&&c<grid[0].size()&&grid[r][c]==1&&!vis[r][c])
                {
                    q.push({r,c});
                    vis[r][c]=true;
                }
                
            }
        }
      
    }
};