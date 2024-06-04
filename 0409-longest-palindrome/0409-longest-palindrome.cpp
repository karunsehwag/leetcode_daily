class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> mp;
        for(char ch:s)
        {
            mp[ch]++;
        }
        int ans=0;
        int count=0;
        
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            ans+=it->second/2;
            if(it->second%2)
                count=1;
            
        }
        return 2*ans+count;
    }
};