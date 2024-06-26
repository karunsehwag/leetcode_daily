class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int pre=0,res=0;
        vector<int> mod(k);
        mod[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            pre=(pre+nums[i]%k+k)%k;
            res+=mod[pre];
            mod[pre]++;
        }
        return res;
        
    }
};