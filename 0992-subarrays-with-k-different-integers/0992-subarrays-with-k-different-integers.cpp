class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
    int atmost(vector<int>& nums,int k)
    {
        unordered_map<int,int> mp;
        int left=0,right=0,ans=0;
        while(nums.size()>right)
        {
            mp[nums[right]]++;
            while(mp.size()>k)
            {
                mp[nums[left]]--;
                if(mp[nums[left]]==0)
                    mp.erase(nums[left]);
                left++;
            }
            ans+=right-left+1;
            right++;
        }
        return ans;
    }
};