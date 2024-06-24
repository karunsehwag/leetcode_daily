class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<bool> flipped(nums.size(),false);
        int valid=0;
        int flip=0;
         for(int i=0;i<nums.size();i++)
         {
             
             if(i>=k)
             {   if(flipped[i-k])
                    valid--;
             }
         
        if(valid%2==nums[i])
        {
            if(i+k>nums.size())
                return -1;
            
            valid++;
            flipped[i]=true;
            flip++;
        }
         }
        return flip;
    }
};