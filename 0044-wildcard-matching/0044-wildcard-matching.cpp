class Solution {
public:
    bool rec(int i,int j,string& s,string& p,vector<vector<int>>& vec)
    {
        if(i==s.size()&&j==p.size())
            return 1;
        if(j>=p.size())
            return 0;
        if(i==s.size())
        {
            for(int k=j;k<p.size();k++)
            {
                if(p[k]!='*')
                    return false;
            }        
              return true;
        }
        if(vec[i][j]!=-1)
            return vec[i][j];
        if(p[j]=='?'||s[i]==p[j])
             return vec[i][j]=rec(i+1,j+1,s,p,vec);
        else if(p[j]=='*')
            return vec[i][j]=rec(i+1,j,s,p,vec)|rec(i,j+1,s,p,vec);
        return vec[i][j]=false;      
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> vec(s.size()+1,vector<int>(p.size()+1,-1));
        
        return rec(0,0,s,p,vec);
        
    }
};