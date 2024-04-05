class Solution {
public:
    string makeGood(string s) {
        stack<char> ch;
        for(char x:s)
        {
            if(ch.empty())
                ch.push(x);
            else if(x==ch.top())
                ch.push(x);
            else if(ch.top()==tolower(x)||toupper(x)==ch.top())
                ch.pop();
            else
                ch.push(x);
        }
        string ans="";
        while(!ch.empty())
        {
            ans=ch.top()+ans;
            ch.pop();
        } 
            return ans;
        
    }
};