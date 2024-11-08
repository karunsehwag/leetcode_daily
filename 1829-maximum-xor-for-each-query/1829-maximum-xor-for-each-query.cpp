class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int Bit) {
        int val=pow(2,Bit)-1;
        vector<int> ans(nums.size(),0);
        int store=0;
        ans[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
              ans[i]=ans[i-1]^nums[i];         
        }
        vector<int> vec;
        for(int j=nums.size()-1;j>=0;j--)
        {
            vec.push_back(val^ans[j]);
        }
        return vec;      
    }
};