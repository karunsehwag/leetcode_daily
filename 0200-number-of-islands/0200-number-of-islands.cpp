class Solution {
public:
    void rec(int row,int col,vector<vector<int>> &vec,vector<vector<char>>& grid)
    {
        vec[row][col]=1;
        vector<pair<int,int>> ve={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty())
        {
           int n1=q.front().first;
           int m1=q.front().second;
           q.pop();
                for(int i=0;i<4;i++)
                { 
                    int n=ve[i].first+n1;
                    int m=ve[i].second+m1;
                    if(n>=0&&n<vec.size()&&m>=0&&m<vec[0].size()&&!vec[n][m]&&grid[n][m]=='1')
                        {
                         q.push({n,m});
                         vec[n][m]=1;
                        }

                }

            
        }




    }
    int numIslands(vector<vector<char>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vec(n,vector<int>(m,0));
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { 
                if(!vec[i][j]&&grid[i][j]=='1')
               {count++;
                rec(i,j,vec,grid); 
                }
               
            }
        }
        return count;   
    }
};