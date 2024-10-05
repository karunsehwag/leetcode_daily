class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v1(26,0),v2(26,0);
        int l1,l2,ans=0,count=0;
        l1=s1.length();
        l2=s2.length();
        char ch;
        for(auto it=s1.begin();it!=s1.end();it++)
        {
            v1[*it-'a']++;     
        }
        for(auto it=s2.begin();it!=s2.end();it++)
        {   
            if(l1>count)
            {
             v2[*it-'a']++;   
             count++;
             
            }
            else{
        
                if(v1==v2)
                {
                    ans=1;
                    break;
                }
                v2[*it-'a']++;
                v2[*(it-l1)-'a']--;
                
            }
            
        }
         if(v1==v2)
                {
                    ans=1;
                    
                }
        
    return ans; }
};