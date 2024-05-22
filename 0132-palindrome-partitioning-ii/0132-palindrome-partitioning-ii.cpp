class Solution {
public:
    bool palindrome(string& s,int i,int j)
    {
        while(j>=i)
        {
            if(s[i]!=s[j])
                return false;
            j--;
            i++;
        }
        return true;
    }
    
    int backtrack(string& s,int n,int i,vector<int>& vec)
    {
        if(i>=n)
            return 0;
        if(vec[i]!=-1)
            return vec[i];
        int ans=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(palindrome(s,i,j))
            {
                int cost=1+backtrack(s,n,j+1,vec);
                ans=min(ans,cost);
            
            }
        }
        return vec[i]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> vec(n,-1);
        return backtrack(s,n,0,vec)-1;
        
    }
};