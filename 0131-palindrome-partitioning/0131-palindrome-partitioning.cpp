class Solution {
public:
    bool palindrome(string& s,int i,int j)
    {
        while(j>=i)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void backtrack(string& s,int ind,int n,vector<vector<string>>& str,vector<string> ans)
    {
        if(ind==n)
        {
            str.push_back(ans);
            return ;   
        }
            
        
        for(int j=ind;j<n;j++)
        {
            if(palindrome(s,ind,j))
            {
               ans.push_back(s.substr(ind,j - ind + 1));
               backtrack(s,j+1,n,str,ans);
                ans.pop_back();
            }
        }
        return ;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string> ans;
        backtrack(s,0,s.size(),vec,ans);
        return vec;
    }
};