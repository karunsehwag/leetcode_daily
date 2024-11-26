class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> vec(n,0);
        for(auto it:edges)
        {
            vec[it[1]]++;
        }
        
        int count=0;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==0)
            {
                ans=i;
                count++;
            }
        }
        
        return count==1?ans:-1;
    }
};