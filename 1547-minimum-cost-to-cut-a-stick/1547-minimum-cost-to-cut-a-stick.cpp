class Solution {
public:
    int backtrack(int j,int i,vector<int>& cuts,vector<vector<int>>& vec)
    {
        if(i+1==j)
            return 0;
           int ans=INT_MAX; 
           if(vec[i][j]!=-1)
               return vec[i][j];
            for(int k=i+1;k<j;k++)
            {
        int sum=cuts[j]-cuts[i]+backtrack(k,i,cuts,vec)+backtrack(j,k,cuts,vec);
                ans=min(ans,sum);
            }
        return vec[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> vec(cuts.size(),vector<int>(cuts.size(),-1));
        return backtrack(cuts.size()-1,0,cuts,vec);
    }
};