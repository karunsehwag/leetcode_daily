class Solution {
public:
    string makeFancyString(string s) {
        
        int count=0;
        string ans="";
        char it='-';
        for(char ch:s)
        {
           if(it!=ch)
           {   
               if(count==1)
                 ans+=it;
                else if(count==2||count>=2)
                {ans+=it;
                 ans+=it;
                }
               count=1;
               it=ch;
              
           }
            else if(it==ch)
            {
                count++;
            }
        }
       
               if(count==1)
                 ans+=it;
               else if(count==2||count>=2)
                    ans=ans+it+it;
            
              
        
        return ans;
        
    }
};