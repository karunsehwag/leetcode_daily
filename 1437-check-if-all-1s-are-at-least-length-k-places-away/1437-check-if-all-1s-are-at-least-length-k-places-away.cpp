class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int in=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i])
            {  if(in==-1)
               {
                in=i;
               }
             else
             {
                if(k>=i-in)
                    return false;
                 in=i; 
             }
            }
        }
        return true;    
    }
};