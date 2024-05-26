class Solution {
    int MOD = 1000000007;
public:
    int backtrack(int n,int ab,int l,vector<vector<vector<int>>>& vec)
    {
      if(ab>=2||l>=3)
          return 0;
      if(n==0)
          return 1;
        
        if(vec[n][ab][l]!=-1)
            return vec[n][ab][l];
int count=0;       
count=backtrack(n-1,ab,0,vec);
count=(count+backtrack(n-1,ab+1,0,vec))%MOD;
count=(count+backtrack(n-1,ab,l+1,vec))%MOD;        
        
        return vec[n][ab][l]=count;
    }
    int checkRecord(int n) {
        string str="";
        vector<vector<vector<int>>> vec(n+1,vector<vector<int>>(3,vector<int>(3,-1)));
       return  backtrack(n,0,0,vec);
        
    }
};