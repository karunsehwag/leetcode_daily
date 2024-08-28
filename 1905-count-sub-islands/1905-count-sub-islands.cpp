class Solution {
public:
    bool dfs(int r,int c,vector<vector<int>>& grid1,vector<vector<int>>& grid2,vector<vector<int>>& vis)
    {
        bool flag = true;
        int m = grid1.size();
        int n = grid1[0].size();
        vis[r][c] = 1;
        vector<int> dx={-1,0,+1,0};
        vector<int> dy={0,+1,0,-1};
        if(grid1[r][c]==0)
            flag = false;
        for(int i=0;i<4;i++)
        {
            int nr = r+dx[i];
            int nc = c+dy[i];
            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid2[nr][nc] == 1)
            {
                bool flag2 = dfs(nr,nc,grid1,grid2,vis);
                flag = flag && flag2;
            }
        }
        return flag;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and grid2[i][j]==1)
                {
                    if(dfs(i,j,grid1,grid2,vis))
                        count++;
                }
            }
        }
        return count;
    }
};