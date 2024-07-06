class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& grid)
    {
       if(0>i||0>j||i>=grid.size()||j>=grid[0].size()||grid[i][j]==0) 
           return 0;
        
       int gold=grid[i][j];
        grid[i][j]=0;
       int ans=max(rec(i+1,j,grid),max(rec(i-1,j,grid),max(rec(i,j+1,grid), rec(i,j-1,grid))));
        grid[i][j]=gold;
      return ans+gold;  
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxv=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {   
               if(grid[i][j]!=0)
                 maxv=max(maxv,rec(i,j,grid));
            }
        }
        
        return maxv;
        
    }
};