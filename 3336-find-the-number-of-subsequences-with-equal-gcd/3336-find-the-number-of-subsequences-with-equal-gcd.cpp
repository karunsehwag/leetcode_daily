class Solution {
public:
    int mod=1e9+7;
    int rec(int in,vector<int>& nums,int g1,int g2,long long int dp[nums.size()+1][201][201])
    {
        if(in>=nums.size())
            return g1&&g2&&(g1==g2);
        
        if(dp[in][g1][g2]!=-1)
            return dp[in][g1][g2];
        
        long long int t1=rec(in+1,nums,gcd(nums[in],g1),g2,dp)%mod;
        long long int t2=rec(in+1,nums,g1,gcd(nums[in],g2),dp)%mod; 
        long long int t3=rec(in+1,nums,g1,g2,dp)%mod;
        return dp[in][g1][g2]=(t1+t2+t3)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
    long long int dp[nums.size()+1][201][201];
    memset(dp,-1,sizeof(dp));
    return rec(0,nums,0,0,dp);
        
    }
};