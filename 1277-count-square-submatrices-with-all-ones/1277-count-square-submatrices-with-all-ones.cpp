class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int answer=0;
        vector<vector<int>> ans(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               if(matrix[i][j]==1&(i==0||j==0))
               {ans[i][j]=1;
               answer++;}
                else if(matrix[i][j]==1)
                {
                    ans[i][j]=1+min(ans[i-1][j],min(ans[i][j-1],ans[i-1][j-1]));
                    answer=answer+ans[i][j];
                } 
                
            }
        }
     
        return answer;
        
    }
};