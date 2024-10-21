class Solution {
public:
    int maxUniqueSplit(string s) 
    {
       set<string> st;
       return backtrack(st,s,0);
    }
    int backtrack(set<string> st, string& s,int start)
    {
        if(start>=s.size())
            return 0;
        int maxsplit=0;
        for(int i=start+1;i<=s.size();i++)
        {
            string str=s.substr(start,i-start);
            if(st.find(str)==st.end())
            {
                st.insert(str);
                maxsplit=max(maxsplit,1+backtrack(st,s,i));
                st.erase(str);
            }
        }
        return maxsplit;
    }
};