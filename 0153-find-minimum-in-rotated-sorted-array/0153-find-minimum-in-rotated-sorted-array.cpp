class Solution {
public:
    int pivot(vector<int>& nums)
    {
        int low=0,high=nums.size()-1;
        if(nums[low]<=nums[high])
            return 0;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(nums[0]<=nums[mid])
                low=mid+1;
            else
                high=mid-1;
        }
        return low;
    }
    int findMin(vector<int>& nums) {
       return nums[(pivot(nums))];
    }
};