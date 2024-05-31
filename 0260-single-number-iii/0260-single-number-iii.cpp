class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int> mp;
        for(int x:nums)
        {
            mp[x]++;
        }
        vector<int> ans;
        for(int x:nums)
        {
            if(mp[x]==1)
                ans.push_back(x);
        }
        return ans;
        
    }
};