class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> vec(n+1,vector<int>(n+1,0));
        string t=s;
        reverse(t.begin(),t.end());
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    vec[i][j]=1+vec[i-1][j-1];
                else
                    vec[i][j]=max(vec[i-1][j],vec[i][j-1]);
            }
        }
      
        
        return n-vec[n][n];
        
    }
};