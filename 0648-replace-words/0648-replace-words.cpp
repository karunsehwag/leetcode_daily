class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        
        set<string> st;
        int size=0;
        for(string it:dictionary)
        {
            st.insert(it);
            size=max(size,int(it.size()));
        }
        string ans="";
        string check="";
        for(int i=0;i<sentence.size();i++)
        {   check+=sentence[i];
            if(sentence[i]==' ')
            {  
                ans+=check;
                check="";
              
             }
            else
            {
                
                if(st.count(check))
                {  
                    ans+=check;
                    check="";
                    while(sentence.size()>i&&sentence[i]!=' ')
                        i++;
                    if(sentence.size()>i)
                       ans+=' ';
                    
                }
            }
           
        }
        
        ans+=check;
        return ans;
        
        
        
    }
};