class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count =0;
        int ans=0;
        for(int x:nums)
        {
            mp[x]++;
            count=max(count,mp[x]);
        }
        for(auto  it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==count)
                ans+=count;
        }
        
        
        return ans;
    }
};