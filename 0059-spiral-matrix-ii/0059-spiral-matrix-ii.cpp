class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> vec(n,vector<int>(n,0));
        int i=0,j=0;
        int k=n,m=n;
        int ans=1;
        while(i<k&&j<m)
        {
            for(int o=j;o<m;o++)
            {
                vec[i][o]=ans;
                ans++;
            }
            i++;
            for(int o=i;o<m;o++)
            {
                vec[o][m-1]=ans;
                ans++;
            }
            m--;
            if(i<k)
            {
                for(int o=m-1;o>=j;o--)
                {   
                    vec[k-1][o]=ans;
                    ans++;
                    
                }
               k--;  
            }
            if(j<m)
            {
                for(int o=k-1;o>=i;o--)
                {
                    vec[o][j]=ans;
                    ans++;
                }
             j++;   
            }
            
        }
       return vec; 
    }
};