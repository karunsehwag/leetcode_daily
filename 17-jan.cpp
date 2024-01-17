class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int t:arr)
        {
            mp[t]++;
        }
        set<int> st;
        for(auto itr:mp)
        {
            int freq = itr.second;
            if(st.find(freq)!=st.end())
                return false;
            st.insert(freq);
        }
        return 1;
    }
};