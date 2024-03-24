class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int k=nums[0];
        for(int i=1;i<nums.size();i++)
        { if(k==nums[i])
              break;
              k=nums[i];  
        }
        return k;
    }
};