class Solution {
public:
    int y=0;
    void backtrack(string& s,set<string>& st,int i,string str,vector<string>& ans,int n)
    {
        if(i==n)
        {    ans.push_back(str.substr(1));
        return;}
         
        for(int j=i;j<=n;j++)
        {    
            if(st.find(s.substr(i,j-i))!=st.end())
            {  
                backtrack(s,st,j,(str+" "+s.substr(i,j-i)),ans,n);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<string> ans;
        int n=s.size();
        for(string x:wordDict)
        {
            st.insert(x);
        }
        
        string x;
        
        backtrack(s,st,0,x,ans,n);
        return ans;
        
    }
};