class Solution {
public:
    string compressedString(string word) {
        int count=0;
        char prev=word[0];
        string ans="";
        for(char ch:word)
        {
            if(prev==ch)
            {
                count++;
                if(count==9)
                {
                    ans+="9";
                    ans+=ch;
                    count=0;
                    
                }
            }
            else{
                
              
                if(count!=0)
                { ans += to_string(count);
                   ans += prev;}
                count=1;
                prev=ch;
            }
        }
    
        if(count!=0)
           { ans += to_string(count);
            ans += prev;}
        
       return ans; 
    }
};