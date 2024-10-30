class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> interval;
        for(vector<int> it:intervals)
        {
            interval.push_back({it[0],1});
            interval.push_back({it[1]+1,-1});
        }
        sort(interval.begin(),interval.end());
        int concurrent=0;
        int maxconcurrent=0;
        for(auto p:interval)
        {
            concurrent+=p.second;
            maxconcurrent=max(maxconcurrent,concurrent);
        }
        return maxconcurrent;
        
    }
};