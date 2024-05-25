class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n,1);
        vector<int> prev(n,1);
        int sum=0,sum2=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]>nums[j]&&vec[j]+1>vec[i])
                {
                    vec[i]=vec[j]+1;
                }
            }
            sum=max(vec[i],sum);
        }
        reverse(nums.begin(),nums.end());
         for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(nums[i]>nums[j]&&prev[j]+1>prev[i])
                {
                    prev[i]=prev[j]+1;
                }
            }
            sum2=max(prev[i],sum2);
        }
        reverse(prev.begin(),prev.end());
        int val=-1;
        for(int i=0;i<n;i++)
        {  if(vec[i]>1&&prev[i]>1)
            val=max(val,vec[i]+prev[i]-1);
        }
        return n-val;
        
    }
};