class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int answer=0;
        int ans=0,count=0;
        while(right<nums.size())
        {
            if(nums[right]==0)
                   k--;
            while(0>k)
            {
                if(nums[left]==0)
                    k++;
                left++;
            }
            ans=max(ans,static_cast<int>(right-left+1));
            right++;
        }
        return ans;
    }
};