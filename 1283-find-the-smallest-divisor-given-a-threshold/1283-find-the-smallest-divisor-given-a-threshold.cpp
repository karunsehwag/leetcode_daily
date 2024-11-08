class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) 
    {
        int low=1;
        int high=INT_MIN;
        for(int x:nums)
        {
            
            high=max(x,high);
        }
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(possible(mid,nums,threshold))
              low=mid+1;
            else
              high=mid-1; 
        }
        return low;
        
    }
    int possible(int mid,vector<int>&nums,int threshold)
    {
        int cnt=0;
        for(int x:nums)
        {
            cnt+=(x+mid-1)/mid;
        }
        return threshold<cnt;

    }
};