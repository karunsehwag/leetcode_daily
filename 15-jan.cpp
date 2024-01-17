class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> vec(100001,0);
        vector<int> vec1(100001,0);
        for(vector<int> it:matches)
        {
            vec[it[0]]++;
            vec1[it[1]]++;
        }
        vector<vector<int>> ans;
        ans.push_back({});
        ans.push_back({});
        for(int i=0;i<100001;i++)
        {
            if(vec[i]>0&&vec1[i]==0)
               ans[0].push_back(i);
            if(vec1[i]==1)
                ans[1].push_back(i);   
        }
    return ans;    
    }
};