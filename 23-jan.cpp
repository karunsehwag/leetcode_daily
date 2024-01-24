class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp={0};
        int res=0;
        for(string str:arr)
        {
            int a=0,dup=0;
            for(char ch:str)
            {
                dup |=a&(1<<(ch-'a'));
                a|=1<<(ch-'a');
            }
            if(dup>0)
               continue;
            for(int i=dp.size()-1;i>=0;i--)
            {
                if((dp[i]&a)>0) continue;
                dp.push_back(dp[i]|a);
                res=max(res,__builtin_popcount(dp[i] | a));
            }   
        }
        return res;
    }
};