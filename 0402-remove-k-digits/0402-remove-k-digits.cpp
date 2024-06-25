class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (char digit : num) {
            // Ensure the digit stack is always increasing
            while (!ans.empty() && ans.back() > digit && k > 0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(digit);
        }

        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        int start = 0;
        while (start < ans.size() && ans[start] == '0') {
            start++;
        }
        
        ans = ans.substr(start);
        
        return ans.empty() ? "0" : ans;
    }
};
