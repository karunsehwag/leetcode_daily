class Solution {
public:
    int dp(int in,int val,int maxv,vector<int>& nums)
    { 
        if (val == maxv) {  
            return 1 << (nums.size() - in);
        }
        if (in >= nums.size()) {
            return 0;
        }
        int take=dp(in+1,val|nums[in],maxv,nums);
        int nottake=dp(in+1,val,maxv,nums);
        return take+nottake;     
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxv=0;
        for(int x:nums)
            maxv|=x;
         return dp(0,0,maxv,nums);    
    }
};