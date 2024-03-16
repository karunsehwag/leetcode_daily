class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                sum=sum-1;
            else if(nums[i]==1)
                sum++;
            if(sum==0)
                ans=max(ans,i-mp[sum]+1);
            if(mp.find(sum)!=mp.end())
            {ans=max(ans,i-mp[sum]);}
            if(mp.find(sum)==mp.end())
              mp[sum]=i;
        }
        return ans;
    }
};