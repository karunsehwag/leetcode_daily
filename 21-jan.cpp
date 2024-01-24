class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int rob=0;
        int norob=0;
        for(int i=0;i< nums.size();i++)
        {
            int nrob=norob+nums[i];
            int nnrob=max(norob,rob);
            rob=nrob;
            norob=nnrob;
        }

        return max(norob,rob);
    }
};