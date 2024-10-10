class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> vec(nums.size(),-1);
        for(int i=0;i<2*nums.size()-1;i++)
        {
            while(!st.empty()&&nums[st.top()]<nums[i%nums.size()])
            {
                vec[st.top()]=nums[i%nums.size()];
                st.pop();
                
            }
            st.push(i%nums.size());
        }
        return vec;
        
    }
};