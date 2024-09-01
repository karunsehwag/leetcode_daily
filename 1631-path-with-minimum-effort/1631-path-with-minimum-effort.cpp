class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                a=min(a,heights[i][j]);
                b=max(b,heights[i][j]);
            }
        }
        int high=b-a;
        int low=0;
        int n=heights.size();
        int  m=heights[0].size();
        while(high>low)
        {
            int mid=low+(high-low)/2;
            vector<vector<int>> vis(n,vector<int>(m,0));
            if(dfs(mid,heights,0,0,vis))
            {
                high=mid;
            }
            else
            {
                low=mid+1;
            }
        }
        return high;
    }
    
    bool dfs(int mid,vector<vector<int>>& vec,int i,int j,vector<vector<int>>& vis)
    {  
       if (i == vec.size() - 1 && j == vec[0].size() - 1) return true;
        vis[i][j]=1;
        vector<int> dr={-1,0,1,0,-1};
        for(int k=0;k<4;k++)
        {
            int row=dr[k]+i;
            int col=dr[k+1]+j;
           
            if(row>=0&&row<vec.size()&&col>=0&&col<vec[0].size()&&mid>=abs(vec[i][j]-vec[row][col])&&vis[row][col]==0)
            {   if(dfs(mid,vec,row,col,vis))
                    return true;
                  
            }
        }
        return false;
    }
};