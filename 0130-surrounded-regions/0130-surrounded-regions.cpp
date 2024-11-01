class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0||j==0||i==n-1||j==m-1)&&board[i][j]=='O')
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1};
        while(!q.empty())
        {
            auto it =q.front();
            q.pop();
            int x=it.first;
            int y=it.second;
            for(int i=0;i<dir.size()-1;i++)
            {
                int nx=x+dir[i];
                int ny=y+dir[i+1];
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&vis[nx][ny]==0&&board[nx][ny]=='O')
                {
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }    
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j]==0&&board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        
        
    }
};