class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left=0,right=0;
        int ans=0;
        int sum=0;
        while(nums.size()>right)
        {
            sum+=nums[right];
            while(left<right&&sum>goal)
            {
                sum-=nums[left];
                left++;
            }
            if(sum==goal)
            {
                int r=left;
                int s=sum;
                while(r< right && nums[r] == 0)
                {
                    ans++;
                    r++;
                }
               
               ans++; 
            }
            right++;
        }
        return ans;
        
    }
};