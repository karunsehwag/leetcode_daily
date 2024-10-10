class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++)
        {
            while(!st.empty()&&nums2[st.top()]<nums2[i])
            {
                mp[nums2[st.top()]]=nums2[i];
                st.pop();
            }
            mp[nums2[i]]=-1;
            st.push(i);            
        }
    vector<int> ans;
    for(int x:nums1)
    {
        ans.push_back(mp[x]);
    }
        return ans;
        
    }
};