class Solution {
public:
    bool check(string t, string s)
    {
           if(s.size()!=t.size())
            return 0;
      vector<int> vec(256,-1);
      for(int i=0;i<s.size();i++)
      {
          if(vec[s[i]-'\0']==-1)
             vec[s[i]-'\0']=t[i]-'\0';
          else if(vec[s[i]-'\0']!=t[i]-'\0')
              return 0;   
      }
        return 1;
    }
    
    bool isIsomorphic(string t, string s) {
  
        return check(s,t)&&check(t,s);
    }
};