class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
       sort(g.begin(),g.end());
       sort(s.begin(),s.end());
       int  count=0;
       int stor=0;
       for(int i=0;i<s.size();i++)
       {
           if(stor<g.size()&&s[i]>=g[stor])
           {
               stor++;
               count++;
           }
       }
        
        return count;
        
    }
};