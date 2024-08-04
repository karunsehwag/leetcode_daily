class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n/2;i++)
        {
            for(int j=0;j<m/2;j++)
            {
                int ones=0;
                if(grid[i][j]==1) ones++;
                if(grid[n-i-1][j]==1) ones++;
                if(grid[i][m-j-1]==1) ones++;
                if(grid[n-i-1][m-j-1]) ones++;
                
                if(ones==4||ones==0)
                    continue;
                else if(ones>=2)
                {
                    ans+=(4-ones);
                    
                }
                else
                    ans+=ones;
            }
        }
        if(n%2==0&&m%2==0) return ans;
        int pal=0;
        int ones=0;
        
        if(m%2)
        {
            for(int i=0;i<n/2;i++)
            {
                if(grid[i][m/2]==1&&grid[n-i-1][m/2]==1) pal++;
                if(grid[i][m/2]!=grid[n-i-1][m/2])
                {
                    ans++;
                    ones++;
                }
            }
        }
        if(n%2)
        {
            for(int j=0;j<m/2;j++)
            {
                if(grid[n/2][j]==1&&grid[n/2][m-j-1]==1) pal++;
                if(grid[n/2][j]!=grid[n/2][m-j-1]) 
                {
                    ans++;
                    ones++;
                }
            }
        }
        if(pal%2==1)
        {
            if(ones==0) ans+=2;
        }
        if(n%2==1&&m%2==1&&grid[n/2][m/2]==1) ans++;
        return ans;
        
    }
};