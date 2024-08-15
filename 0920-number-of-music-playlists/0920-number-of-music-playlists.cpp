class Solution {
public:
    int numMusicPlaylists(int n, int goal, int k) {
        int Mod=1e9+7;
        vector<vector<long>> vec(goal+1,vector<long>(n+1,0));
        vec[0][0]=1;
        for(int i=1;i<=goal;i++)
        {
            for(int j=1;j<=min(n,i);j++)
            {
                vec[i][j]=(vec[i-1][j-1]*(n-j+1))%Mod;
                if(j>k)
                    vec[i][j]=(vec[i][j]+vec[i-1][j]*(j-k))%Mod;
            }
        }
        
        return vec[goal][n];
        
    }
};