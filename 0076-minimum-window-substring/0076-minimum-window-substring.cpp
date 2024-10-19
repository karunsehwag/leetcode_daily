class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n=s.size();
        int m=t.size();
        int j=0;
        int count=m;
        if(s.empty()||t.empty()||m>n)
           return "";
        unordered_map<char,int> mp;
        int minl=INT_MAX;
        int st=0;
        for(char ch:t)
           mp[ch]++;   
        for(int i=0;i<n;i++)
        {
            if(mp[s[i]]-->0)
               count--;
            while(count==0)
            {
             if(minl>i-j+1)
             {
                 minl=i-j+1;
                 st=j;
             }
             if (mp.find(s[j]) != mp.end()) {
                    mp[s[j]]++;
                    if (mp[s[j]] > 0) {
                        count++;
                    }
                }
                
                j++;
            

            }   

        }   
        return minl==INT_MAX? "":s.substr(st,minl);
    }
};