class Solution {
public:
    int findTheLongestSubstring(string s) {
        int prefixxor=0;
        int charactermap[26]={0};
        charactermap['a'-'a']=1;
        charactermap['e'-'a']=2;
        charactermap['i'-'a']=4;
        charactermap['o'-'a']=8;
        charactermap['u'-'a']=16;
        vector<int> mp(32,-1);
        int longest=0;
        for(int i=0;i<s.size();i++)
        {
            prefixxor^=charactermap[s[i]-'a'];
            if(mp[prefixxor]==-1&&prefixxor!=0)
                mp[prefixxor]=i;
            
            longest=max(longest,i-mp[prefixxor]);
        }
        return longest;
    }
};