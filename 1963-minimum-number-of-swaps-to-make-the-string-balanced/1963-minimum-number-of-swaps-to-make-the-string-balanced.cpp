class Solution {
public:
    int minSwaps(string s) {
        stack<char> ch;
        int st=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            {
                ch.push(s[i]);
            }
            else
            {
                if(!ch.empty()) ch.pop();
                else
                    st++;
            }
        }
        
        return (st+1)/2;    
        
    }
};