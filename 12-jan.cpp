class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.size();
        int k=n/2;
        int c1=0;
        int c2=0;
        for(int i=0;i<k;i++)
           {
               if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
               {
                   c1++;
               }
           }
            for(int i=k;i<n;i++)
           {
               if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
               {
                   c2++;
               }
           }
        if(c1==c2)
          return 1;
          return 0;
    }
};