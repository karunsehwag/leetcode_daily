class Solution {
public:
     int rec(vector<int>& piles,int i,int n,vector<vector<int>>& vec)
    {
        if(i>=n)
            return piles[i];
        if(vec[i][n]!=-1)
            return vec[i][n];
        int s1=piles[i]-rec(piles,i+1,n,vec);
        int s2=piles[n]-rec(piles,i,n-1,vec);
        return vec[i][n]=max(s1,s2);
    }
    bool predictTheWinner(vector<int>& piles) {
         long long sum=0;
        
        for(int x:piles)
            sum+=x;
        vector<vector<int>> vec(piles.size()+1,vector<int>(piles.size()+1,-1));
        int  ans=rec(piles,0,piles.size()-1,vec);
        return ans>=0;
        
        
    }
};