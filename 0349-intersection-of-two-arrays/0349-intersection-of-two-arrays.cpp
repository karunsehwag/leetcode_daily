class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        vector<int> vec;
        for(int x:nums1)
        {
            if(mp[x]==0)
                mp[x]++;
        }
           for(int x:nums2)
        {
            if(mp[x]==1)
            {   
                vec.push_back(x);
                mp[x]++;
            }
        }
      
    return vec;
        
    }
};