class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0,index=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=max(ans,nums[i]);
        }
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(ans==nums[i])
                count++;
            else
                count=0;
            index=max(count,index);
        }
        return index;
        
    }
};