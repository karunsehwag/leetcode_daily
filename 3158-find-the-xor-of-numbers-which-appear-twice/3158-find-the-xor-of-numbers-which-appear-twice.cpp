class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        map<int,int> mp;
        int ans=0;
        for(int x:nums)
        {
            mp[x]++;
            if(mp[x]==2)
                ans^=x;
        }
        return ans;
        
    }
};