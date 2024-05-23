class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,1);
        vector<int> dp(n,1);
        int val=INT_MIN;
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<=i;prev++)
            {
                if(nums[i]>nums[prev]&&dp[prev]+1>dp[i])
                {
                    dp[i]=dp[prev]+1;
                    vec[i]=vec[prev];
                }
                else if(nums[i]>nums[prev]&&dp[prev]+1==dp[i])
                {
                    vec[i]=vec[prev]+vec[i];
                }
                
                val=max(val,dp[i]);
            }
           
        }
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(dp[j]==val)
                count+=vec[j];
        }
        return count;
        
        
    }
};