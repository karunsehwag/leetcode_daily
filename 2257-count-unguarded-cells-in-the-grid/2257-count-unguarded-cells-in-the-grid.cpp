class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> vec(m,vector<int>(n,0));
        for(auto it:guards)
        {
            vec[it[0]][it[1]]=3;
        }
        for(auto it:walls)
        {
            vec[it[0]][it[1]]=1;
        }
        for(auto it :guards)
        {
            int up=it[0]-1;
            int down=it[0]+1;
            while(up>=0)
            {
              if(vec[up][it[1]]==0||vec[up][it[1]]==-1)
                  vec[up][it[1]]=-1;
                else
                {
                    break;
                }
                up--;
            }
            while(m>down)
            {
               if(vec[down][it[1]]==0||vec[down][it[1]]==-1)
                  vec[down][it[1]]=-1;
                else
                {
                    break;
                }
                down++;  
            }
            int left=it[1]-1;
            int right=it[1]+1;
            while(left>=0)
            {
             if(vec[it[0]][left]==0||vec[it[0]][left]==-1)
                 vec[it[0]][left]=-1;
            else
                break;
                left--;
            }
            while(right<n)
            {
                if(vec[it[0]][right]==0||vec[it[0]][right]==-1)
                    vec[it[0]][right]=-1;
                else
                {
                    break;
                }
                
                right++;
                
            }
        }
        int ans=0;
        
        for(auto it:vec)
        {
            for(int x:it)
            {
                if(x==0)
                    ans++;
            }
            cout<<endl;
        }
        
        return ans;
        
    }
};