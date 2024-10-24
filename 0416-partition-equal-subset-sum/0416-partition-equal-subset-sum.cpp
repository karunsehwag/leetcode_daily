class Solution {
public:
    bool fun(int in,vector<vector<int>>& memo,int sum,vector<int>& nums)
    {
        if(sum==0)
            return true;
        if(sum<0||in>=nums.size())
            return false;
        if(memo[in][sum]!=-1)
            return memo[in][sum];
        bool take=fun(in+1,memo,sum-nums[in],nums);
        int notake=fun(in+1,memo,sum,nums);
        return memo[in][sum]=take||notake;
    }
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        for(int it:nums)
            sum+=it;
        if(sum%2)
            return false;
        sum=sum/2;
        vector<vector<int>> memo(nums.size(),vector<int>(sum+1,-1));
        return fun(0,memo,sum,nums);
    }
};