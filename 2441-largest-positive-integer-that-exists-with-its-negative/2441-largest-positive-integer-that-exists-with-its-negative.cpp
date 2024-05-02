class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> mp;
        int ans=-1;
        for(int x:nums)
        {
            mp.insert(x);
        }
        for(int x:nums)
        {
            if(mp.find(-x)!=mp.end())
                ans=max(x,ans);
        }
        return ans;
        
    }
};