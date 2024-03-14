class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        int count=0;
        int l=0,r=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
                count++;
            while(l<i&&count>goal)
            {
                if(nums[l]==1)
                    count--;
                l++;
            }
            if(count==goal)
            {
                int r=l;
                  while(r<i&&nums[r]==0)
            {
               
                    ans++;
                r++;
            }
                ans++;
            }
           
        }
        return ans;
        
    }
};