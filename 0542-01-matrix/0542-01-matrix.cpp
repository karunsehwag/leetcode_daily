class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        vector<vector<int>> vec(mat.size(),vector<int>(mat[0].size(),INT_MAX));
        
        queue<pair<int,int>> q;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                 if(mat[i][j]==0)
                 {q.push({i,j});
                    vec[i][j]=0;};
            }
        }
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int x=node.first;
            int y=node.second;
            if(x-1>=0)
            {
                
                if(vec[x-1][y]==INT_MAX)
                {
                    q.push({x-1,y});
                    vec[x-1][y]=vec[x][y]+1;
                }
            }
            if(y-1>=0)
            {
               
                if(vec[x][y-1]==INT_MAX)
                {
                    q.push({x,y-1});
                    vec[x][y-1]=vec[x][y]+1;
                }
            }
            if(mat.size()>x+1)
            {
                if(vec[x+1][y]==INT_MAX)
                {
                    q.push({x+1,y});
                    vec[x+1][y]=vec[x][y]+1;
                }
            }
            if(mat[0].size()>y+1)
            {
              
                if(vec[x][y+1]==INT_MAX)
                {
                    q.push({x,y+1});
                    vec[x][y+1]=vec[x][y]+1;
                }
            }
            
            
            
        }
        return vec;
        
    }
};