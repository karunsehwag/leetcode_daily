class Solution {
public:
    int countincteam(vector<int>& vec,int cur,int size,vector<vector<int>>& inc)
    {
        int n=vec.size();
        if(cur==n) return 0;
        if(size==3) return 1;
        if(inc[cur][size]!=-1)
             return inc[cur][size];
        int valid=0;
        
        for(int next=cur+1;next<n;next++)
        {
            if(vec[next]>vec[cur])
            {
                valid+=countincteam(vec,next,size+1,inc);
                
            }
        }
        
        return inc[cur][size]=valid;
    }
      int countdecteam(vector<int>& vec,int cur,int size,vector<vector<int>>& inc)
    {
        int n=vec.size();
        if(cur==n) return 0;
        if(size==3) return 1;
        if(inc[cur][size]!=-1)
             return inc[cur][size];
        int valid=0;
        
        for(int next=cur+1;next<n;next++)
        {
            if(vec[next]<vec[cur])
            {
                valid+=countdecteam(vec,next,size+1,inc);
                
            }
        }
        
        return inc[cur][size]=valid;
    }
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        int team=0;
        vector<vector<int>> inc(n,vector<int>(4,-1));
        vector<vector<int>> dec(n,vector<int>(4,-1));
        
        for(int start=0;start<n;start++)
        {
            team+=countincteam(rating,start,1,inc)+countdecteam(rating,start,1,dec);
        }
        return team;
        
    }
};