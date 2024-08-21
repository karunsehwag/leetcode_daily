class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& vec,string& s)
    {
        if(i==j)
            return 1;
        if(vec[i][j]!=-1)
            return vec[i][j];
        int minc=INT_MAX;
        for(int k=i;k<j;k++)
        {
            minc=min(minc,rec(i,k,vec,s)+rec(k+1,j,vec,s));
        }
        return vec[i][j]=s[i]==s[j]?minc-1:minc;
    }
    int strangePrinter(string s) {
        vector<vector<int>> vec(s.size(),vector<int>(s.size(),-1));
        return rec(0,s.size()-1,vec,s);
        
    }
};