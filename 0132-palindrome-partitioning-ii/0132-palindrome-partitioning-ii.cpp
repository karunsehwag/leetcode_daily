#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    // Helper function to check if a substring is a palindrome
    bool palindrome(const string& s, int i, int j) {
        while (j > i) {
            if (s[i] != s[j])
                return false;
            j--;
            i++;
        }
        return true;
    }

    // Memoized backtrack function to find the minimum cuts
    int backtrack(const string& s, int n, int i, vector<int>& vec) {
        if (i >= n)
            return 0; // No cuts needed if we've reached the end of the string

        if (vec[i] != -1)
            return vec[i]; // Return the memoized result if available

        int ans = INT_MAX;
        for (int j = i; j < n; j++) {
            if (palindrome(s, i, j)) {
                int cost = 1 + backtrack(s, n, j + 1, vec);
                ans = min(ans, cost);
            }
        }
        vec[i] = ans; // Memoize the result for the current starting index
        return ans;
    }

    // Main function to find the minimum cuts needed for a palindrome partitioning
    int minCut(string s) {
        int n = s.size();
        vector<int> vec(n, -1); // Initialize memoization array with -1
        return backtrack(s, n, 0, vec) - 1; // Subtract 1 to get the correct number of cuts
    }
};
