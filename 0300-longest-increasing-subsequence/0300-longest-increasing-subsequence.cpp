class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vec(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int prev_index = i - 1; prev_index >= -1; prev_index--) {
                int notTake = vec[i + 1][prev_index + 1]; 
                
                int take = 0;
                if (prev_index == -1 || nums[i] > nums[prev_index]) {
                    take = 1 + vec[i + 1][i + 1]; 
                }

                vec[i][prev_index + 1] = max(notTake, take);
            }
        }

        return vec[0][0];
    }
};
