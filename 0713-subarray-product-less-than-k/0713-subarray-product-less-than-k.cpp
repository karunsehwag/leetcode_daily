class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int count=0;
        for(int i=0;i<nums.size();i++)
        {   int z=1;
            
            for(int j=i;j<nums.size();j++)
            {    z=nums[j]*z;
                if(k>z)
                  count++;
                if(z>k)
                    break;
                
               
                    
            }
         
        }
        return count;
    }
};