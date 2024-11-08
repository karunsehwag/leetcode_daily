class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int floor=-1;
        int low=0,high=nums.size()-1;
        while(high>=low)
        {
            int mid=(high+low)/2;
            if(target==nums[mid])
            {
                floor=mid;
                high=mid-1;
            }
            else if(target>nums[mid])
            {
                low=low+1;
               
            }
            else
            {
                 high=mid-1;
            }
            
        }
        low=0,high=nums.size()-1;
        int ceil=-1;
           while(high>=low)
        {
            int mid=(high+low)/2;
            if(target==nums[mid])
            {
                ceil=mid;
                low=mid+1;
            }
            else if(target<nums[mid])
            {
                 high=mid-1;
               
            }
            else
            {
                low=mid+1;
            }
            
        }
        
        vector<int> ans;
        ans.push_back(floor);
        ans.push_back(ceil);
        return ans;
    }
};