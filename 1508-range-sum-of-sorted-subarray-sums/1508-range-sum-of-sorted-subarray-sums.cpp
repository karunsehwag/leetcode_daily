class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> vec;
        int mod=pow(10,9)+7;
        for(int i=0;i<nums.size();i++)
        {   int sum=0;
            for(int j=i;j<nums.size();j++)
            {
               sum+=nums[j];
                vec.push_back(sum);
            }
        }
        int ans=0;
        sort(vec.begin(),vec.end());
        
        for(int k=left-1;k<right;k++)
        {
           ans+=vec[k];
           ans=ans%mod;
        }
        return ans;
        
    }
};