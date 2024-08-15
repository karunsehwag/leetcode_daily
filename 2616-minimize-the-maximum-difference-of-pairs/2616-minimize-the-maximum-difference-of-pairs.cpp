class Solution {
public:
    int count(vector<int>& nums,int threshold)
    {
        int index=0,count=0;
        while(nums.size()-1>index)
        {
         if(threshold>=(nums[index+1]-nums[index])) 
         {
             count++;
             index++;
         }
            index++;
        }
        return count;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int low=0,high=nums[nums.size()-1]-nums[0];
        while(high>low)
        {
            int mid=low+(high-low)/2;
            if(count(nums,mid)>=p)
                high=mid;
            else
                low=mid+1;
        }
        return low;    
    }
};