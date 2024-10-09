class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> ch;
        for(char x:s)
        {
            if(!ch.empty()&&ch.top()=='('&&x==')')
                ch.pop();
            else
                ch.push(x);
        }
        return ch.size();
        
        
    }
};