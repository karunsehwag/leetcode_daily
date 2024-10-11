class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int ans = 0;

        while (right < nums.size()) {
            if (nums[right] == 0)
                k--;  // Decrement k when flipping a zero
            
            // If we've flipped more than k zeros, move the left pointer to reduce flips
            while (k < 0) {
                if (nums[left] == 0)
                    k++;  // Increment k when unflipping a zero
                left++;  // Move left pointer to shrink the window
            }
            
            // Calculate the maximum window size
            ans = max(ans, right - left + 1);
            right++;  // Move the right pointer
        }
        
        return ans;
    }
};
