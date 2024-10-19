class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int left=0,right=0,ans=0,count=0;
        while(right<nums.size())
        {
            if(++mp[nums[right++]]==1)
                k--;
            if(k<0)
            {
                mp[nums[left++]]--;
                k++;
                count=0;
            }
            if(k==0)
            {
                while(mp[nums[left]]>1)
                {      
                    mp[nums[left++]]--;
                    count++;
                }
                ans+=(count+1);
            }
        }
        return ans;     
    }
};