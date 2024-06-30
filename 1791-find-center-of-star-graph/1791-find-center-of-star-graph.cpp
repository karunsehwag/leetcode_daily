class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(vector<int> x: edges)
        {
            mp[x[0]]++;
            mp[x[1]]++;
        }
        int ans=-1;
        for(auto x=mp.begin();x!=mp.end();x++)
        {
            if(x->second==edges.size())
                ans=x->first;
        }
        return ans;
        
    }
};