class Solution {
public:
    const int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long int answer = 0;
        stack<int> st;
        
        for (int right = 0; right <= n; right++) {
            while (!st.empty() && (right == n || arr[st.top()] >= arr[right])) {
                int mid = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                
                // Cast to long long to avoid overflow
                long long contribution = static_cast<long long>(arr[mid]) * (right - mid) * (mid - left);
                answer = (answer + (contribution % mod)) % mod;
            }
            st.push(right);
        }
        
        return answer;
    }
};
