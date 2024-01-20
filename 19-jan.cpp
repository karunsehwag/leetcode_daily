class Solution {
public:
   
    int rec(vector<vector<int>>& matrix,int i,int j)
    {
        if(j>=matrix[0].size()||j<0||i>=matrix.size())
           return 0;
        int t=matrix[i][j]+rec(matrix,i+1,j-1);
        int u=matrix[i][j]+rec(matrix,i+1,j);
        int p=matrix[i][j]+rec(matrix,i+1,j+1);
        return min(t,min(u,p));  
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,rec(matrix,i,0));
        }
        return ans;
    }
};