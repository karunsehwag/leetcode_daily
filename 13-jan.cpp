class Solution {
public:
    int minSteps(string s, string t) {

        unordered_map<int,int> mp;
        unordered_map<int,int> mp1;
        for(char it:s)
        {
            mp[it-'a']++;
        }
        for(char it:t)
        {
            mp1[it-'a']++;
        }
        int sum=0;
        for(int i=0;i<26;i++)
        {
            if(mp1[i]-mp[i]>0)
               sum+=mp1[i]-mp[i];
               
        }
        return sum;
    }
};