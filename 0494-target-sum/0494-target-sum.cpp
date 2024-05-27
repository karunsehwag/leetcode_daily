class Solution {
public:
    int backtrack(int ind,vector<int>& nums,int target)
    {   
       
        if(ind==0)
            return (target == nums[0]) + (target == -nums[0]);
        int sum=backtrack(ind-1,nums,target-nums[ind]);
        int sub=backtrack(ind-1,nums,target+nums[ind]);
        return sum+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(nums.size()-1,nums,target);
        
    }
};