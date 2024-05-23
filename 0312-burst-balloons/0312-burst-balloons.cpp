class Solution {
public:
    int backtrack(int i,int j,vector<int>& nums,vector<vector<int>>& vec)
    {  
        if(i>j)
            return 0;
        int ans=INT_MIN;
        if(vec[i][j]!=-1)
            return vec[i][j];
        for(int k=i;k<=j;k++)
        {
            int sum=nums[i-1]*nums[k]*nums[j+1]+backtrack(i,k-1,nums,vec)+backtrack(k+1,j,nums,vec);
            ans=max(sum,ans);
        }
        return vec[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> vec(n+2,vector<int>(n+2,-1));
        return backtrack(1,n,nums,vec);
        
    }
};