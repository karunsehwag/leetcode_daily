class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
       vector<int> nums1,nums2;
        vector<int> ans;
        int pre=1;
        int suf=1;
        
        for(int i=0;i<nums.size();i++)
        {
            pre=pre*nums[i];
            suf=suf*nums[nums.size()-1-i];
            
            nums1.push_back(pre);
            nums2.push_back(suf);
            
        }
        reverse(nums2.begin(),nums2.end());
        for(int i=0;i<nums.size();i++)
        {  if(0>i-1)
              ans.push_back(nums2[i+1]);
           else if(i+1>=nums.size())
               ans.push_back(nums1[i-1]);
         else
            ans.push_back(nums1[i-1]*nums2[i+1]);
           
        }
        
       return ans; 
    }
};