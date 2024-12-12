class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums.size(); // If the array has 2 or fewer elements, no need to process.
        }
        
        int n = 2; // Start at 2 because the first two elements are always valid.
        
        for (int i = 2; i < nums.size(); i++) {
            // Check if the current element can be added.
            if (nums[i] != nums[n - 2]) {
                nums[n] = nums[i];
                n++;
            }
        }
        
        return n; 
    }
};
