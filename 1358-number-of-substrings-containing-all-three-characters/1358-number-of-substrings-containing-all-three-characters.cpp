class Solution {
public:
    int numberOfSubstrings(string s) {
        int a=0,b=0,c=0;
        int l=0,right=0;
        int ans=0;
        while(right<s.size())
        {
            if(s[right]=='a')
                a++;
            if(s[right]=='b')
                b++;
            if(s[right]=='c')
                c++;
            while(right>l&a>0&&b>0&&c>0)
            {
            if(s[l]=='a')
                a--;
            if(s[l]=='b')
                b--;
            if(s[l]=='c')
                c--;
                l++; 
                ans+=s.size()-right;
            }
            
            right++;
            
        }
        
        return ans;
    }
};