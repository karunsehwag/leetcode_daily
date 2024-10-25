class Solution {
public:
    int minDistance(string word1, string word2) {
        
        vector<vector<int>> vec(word1.size()+1,vector<int>(word2.size()+1,0));
        int n=word1.size();
        int m=word2.size();
        for(int i=0;i<=n;i++)
            vec[i][0]=i;
        for(int j=0;j<=m;j++)
            vec[0][j]=j;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            { 
                    if(word1[i-1]==word2[j-1]) 
                      vec[i][j]=vec[i-1][j-1];
                    else
                      vec[i][j]=1+min(vec[i-1][j],min(vec[i][j-1],vec[i-1][j-1]));
    
                }
              
        }
        return vec[n][m];
        
    }
};