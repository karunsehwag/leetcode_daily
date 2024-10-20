class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;
        priority_queue<pair<int,int>> pq;
        for(int x:nums)
        {
            mp[x]++;
        }
        
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        vector<int> ans;
        while(k)
        {
            k--;
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans; 
        
    }
};