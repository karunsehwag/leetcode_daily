class Solution {
public:
    bool wordPattern(string pattern, string s) {
      
        vector<char> vec;
        vector<string> str;
        set<char> st;
        set<string> st2;
        unordered_map<char,string> mp;
        for(char ch: pattern)
        {vec.push_back(ch);
         st.insert(ch);
        }
        string sub="";
        for(int i=0;i<s.size();i++)
        {
           
            if(s[i]==' ')
            {
                if(sub.size()>0)
                {str.push_back(sub);
                 st2.insert(sub);}
                sub="";
            }
            else
                sub+=s[i];
        }
        if(sub.size()>0)
             str.push_back(sub);
        st2.insert(sub);
        if(st.size()!=st2.size())
            return 0;
        if(vec.size()!=str.size())
            return 0;
        for(int i=0;i<str.size();i++)
        {
            if(mp[vec[i]]=="")
                mp[vec[i]]=str[i];
            else if(mp[vec[i]]!=str[i])
                 return 0;
        }
        
        return 1;
        
    }
};