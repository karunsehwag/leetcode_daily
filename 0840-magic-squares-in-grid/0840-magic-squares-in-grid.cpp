class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        
        int count=0;
        for(int row=0;row+2<n;row++)
        {
            for(int col=0;col+2<m;col++)
            {
                if(grid[row+1][col+1]==5&&magic(row,col,grid))
                     count++;
            }
        }
        return count;     
    }
    
    int magic(int row,int col,vector<vector<int>>& grid)
    {
        
        unordered_set<int> st;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {  
               if(grid[row+i][col+j]>=0&&(9>=grid[row+i][col+j]))
               {  
                   st.insert(grid[row+i][col+j]);
               }
                else
                {
                    return 0;
                }
            }
        }
        
        if(9!=st.size())
            return 0;
        if(!((grid[row][col]+grid[row][col+1]+grid[row][col+2])==15))
            return 0;
        if(!((grid[row+1][col]+grid[row+1][col+1]+grid[row+1][col+2])==15))
            return 0;
        if(!((grid[row+2][col]+grid[row+2][col+1]+grid[row+2][col+2])==15))
            return 0;
        if(!((grid[row][col]+grid[row+1][col]+grid[row+2][col])==15))
            return 0;
        if(!((grid[row][col+1]+grid[row+1][col+1]+grid[row+2][col+1])==15))
            return 0;
        if(!((grid[row][col+2]+grid[row+1][col+2]+grid[row+2][col+2])==15))
            return 0;
        if(!((grid[row][col]+grid[row+1][col+1]+grid[row+2][col+2])==15))
            return 0;
        if(!((grid[row][col+2]+grid[row+1][col+1]+grid[row+2][col])==15))
            return 0;
        return 1;
        
    }
};