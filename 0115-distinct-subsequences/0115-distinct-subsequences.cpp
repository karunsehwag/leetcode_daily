class Solution {
public:
    int rec(int i,int j,string& s, string& t,vector<vector<int>>& vec)
    {   if(j==t.size())
           return 1;
        if(i>=s.size()||j>=t.size())
            return 0;
     if(vec[i][j]!=-1)
         return vec[i][j];
     int take=0;
     if(s[i]==t[j])
         take=rec(i+1,j+1,s,t,vec);
     int notake=rec(i+1,j,s,t,vec);
     return vec[i][j]=take+notake;
        
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> vec(s.size()+1,vector<int>(t.size()+1,-1));
        return rec(0,0,s,t,vec);  
    }
};