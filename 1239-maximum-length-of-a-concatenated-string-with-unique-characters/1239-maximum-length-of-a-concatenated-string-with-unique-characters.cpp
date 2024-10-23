class Solution {
public:
    int dp(int x,vector<string>& ans, map<char,int> mp)
    {
        if(x>=ans.size())
            return 0;
        int take=0,notake=0;
        notake=dp(x+1,ans,mp);
        int flag=1;
        for(char ch:ans[x])
        {
            mp[ch]++;
            if(mp[ch]>1)
            {
                flag=0;
                break;
            }   
        }
        if(flag)
            take=ans[x].size()+dp(x+1,ans,mp);
        return max(take,notake);
    }
    int maxLength(vector<string>& arr) {
        
        map<char,int> mp;
        return dp(0,arr,mp);
        
        
    }
};