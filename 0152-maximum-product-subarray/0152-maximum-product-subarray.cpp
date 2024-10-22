class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,sufix=1;
        int ans=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            prefix=prefix*nums[i];
            sufix=sufix*nums[nums.size()-1-i];
            ans=max(ans,max(prefix,sufix));
            if(sufix==0)
                sufix=1;
            if(prefix==0)
                prefix=1;
        }
        return ans;   
    }
};