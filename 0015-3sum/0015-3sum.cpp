class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vec;
        int n = nums.size();
        if (n < 3) return vec;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {
    
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int s = i + 1, e = n - 1;

            while (s < e) {
                int sum = nums[i] + nums[s] + nums[e];

                if (sum == 0) {
                    vec.push_back({nums[i], nums[s], nums[e]});
                    while (s < e && nums[s] == nums[s + 1]) s++;
                    while (s < e && nums[e] == nums[e - 1]) e--;

                    s++;
                    e--;
                } else if (sum > 0) {
                    e--; 
                } else {
                    s++;
                }
            }
        }

        return vec;
    }
};
