class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        
        vector<int> vec1(n,0);
        vector<int> vec2(n,0);
        vec1[0]=height[0];
        for (int i = 1; i < n; i++) {
            vec1[i] = max(vec1[i-1], height[i]);
        }
        vec2[n-1]=height[n-1];
        for (int i = n - 2; i >= 0; i--) {
            vec2[i] = max(vec2[i+1], height[i]);
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (min(vec1[i], vec2[i]) - height[i] > 0)
                ans += min(vec1[i], vec2[i]) - height[i];
        }
        
        return ans;
    }
};
