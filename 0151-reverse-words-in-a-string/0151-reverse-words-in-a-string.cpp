class Solution {
public:
    string reverseWords(string s) 
    {
        int left=0;
        int right=s.size()-1;
        string temp="";
        string ans="";
        while(left<=right)
        {
            char ch=s[left];
            if(ch!=' ')
                temp+=ch;
            else if(ch == ' ')
            {
                 if (!temp.empty()) { 
                    if (!ans.empty()) ans = temp + " " + ans;
                    else ans = temp;
                    temp = "";
                }
            }
            left++;
                
        }
        
        if (temp!="") {
        if (ans!=""&&temp!=" ") ans = temp + " " + ans;
        else ans = temp;
    }
        return ans;
        
    }
};