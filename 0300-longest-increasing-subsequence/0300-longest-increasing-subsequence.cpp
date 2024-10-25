class Solution {
public:
    int rec(int i,vector<int>& nums,int prev,vector<vector<int>>& vec )
    {
        if(i>=nums.size())
            return 0;
        if(vec[i][prev+1]!=-1)
            return vec[i][prev+1];
        int take=0;
        if(prev==-1||nums[i]>nums[prev])
        {  
            take=1+rec(i+1,nums,i,vec);
        }
        int notake=rec(i+1,nums,prev,vec);
        
        return vec[i][prev+1]=max(take,notake);
        
            
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> vec(nums.size()+1,vector<int>(nums.size()+1,-1));
        return rec(0,nums,-1,vec);
        
    }
};