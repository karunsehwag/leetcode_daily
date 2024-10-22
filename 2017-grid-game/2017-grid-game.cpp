class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        if(grid[0].size()==1)
            return 0;
        vector<long long> prefix(grid[0].size(),0),suffix(grid[0].size(),0);
        long long pre=0,suf=0;
        for(int i=0;i<grid[0].size();i++)
        {  
            pre+=grid[0][i];
            prefix[i]=pre;
            suf+=grid[1][i];  
            suffix[i]=suf;
        } 
        long long ans=INT_MIN;
        for(int i=1;i<grid[0].size();i++)
        {
            ans=max(ans,min(suffix[i-1],prefix[grid[0].size()-1]-prefix[i-1]));
        }
        return ans;
        
    }
};