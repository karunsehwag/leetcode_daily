class Solution {
public:
    int check(vector<int>& nums,int mid,int k)
    {
        int count=1;
        int sum=0;
        for(int x:nums)
        {
            sum+=x;
            if(sum>mid)
            {
                count++;
                sum=x;
                if(count>k) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=1,high=0;
        for(int x:nums)
        {
            low=max(low,x);
            high+=x;
        }
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(nums,mid,k))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
           
        return ans;
    }
};