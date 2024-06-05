class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int> mp,mp1;
        vector<int> ans;
        for(vector<int> x:queries)
        {
            if(mp.find(x[0])!=mp.end())
            {
                int col=mp[x[0]];
                mp1[col]--;
                if(mp1[col]==0) mp1.erase(col);
            }
            mp[x[0]]=x[1];
            mp1[x[1]]++;
            ans.push_back(mp1.size());
            
        }
        return ans;
        
        
        
    }
};