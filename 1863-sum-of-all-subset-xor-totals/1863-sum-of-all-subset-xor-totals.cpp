class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result=0;
        for(int x:nums)
        {
            result=result|x;
        }
        return result<<(nums.size()-1);
        
    }
};