class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.empty()||nums[i]<nums[st.top()])
                st.push(i);
        }
        int ans=0;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!st.empty()&&nums[i]>=nums[st.top()])
            {  
                ans=max(static_cast<int>(i-st.top()),ans);
                st.pop();
            }
        }
        return ans;
        
    }
};