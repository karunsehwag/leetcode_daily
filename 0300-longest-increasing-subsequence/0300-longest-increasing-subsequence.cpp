class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> vec(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int notake=vec[i+1][prev+1];
                int take=0;
                if(prev==-1||nums[i]>nums[prev])
                {
                    take=1+vec[i+1][i+1];
                }
                
                vec[i][prev+1]=max(take,notake);
            }
        }
        return vec[0][0];
        
    }
};