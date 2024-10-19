class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0,maxi=0,count=0;
        while(nums.size()>right)
        {
            count+=nums[right];
            if(right-left+1-count>k)
            {count-=nums[left];
             left++;
            }
            maxi=max(maxi,static_cast<int>(right-left+1));
            right++;
        }
        return maxi;
        
    }
};