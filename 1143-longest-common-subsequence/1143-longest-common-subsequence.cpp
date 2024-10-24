class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> vec(n+2,vector<int>(m+2,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                
                if(text1[i-1]==text2[j-1])
                    vec[i][j]=1+vec[i-1][j-1];
                else
                   vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
            }
        }
        
        return vec[n][m];
        
        
    }
};