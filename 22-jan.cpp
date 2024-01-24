class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums)
    {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> vec;
        int k=0;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
               vec.push_back(nums[i]);
        }
        for(int i=1;n>=i;i++)
        {
            if(mp[i]==0)
              vec.push_back(i);
        }
        return vec;
    }
};