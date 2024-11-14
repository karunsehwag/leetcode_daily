class Solution {
public:
    bool check(vector<int>& nums,int mid,int op)
    {
        int count=0;
        for(int x:nums)
        {
            count+=(x+mid-1)/mid-1;
        }
        return op>=count;
    }
    int minimumSize(vector<int>& nums, int op) {
        int low=1,high=0;
        for(int x: nums)
            high=max(x,high);
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,mid,op))
            {
             ans=mid;
             high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        return ans;
    }
};