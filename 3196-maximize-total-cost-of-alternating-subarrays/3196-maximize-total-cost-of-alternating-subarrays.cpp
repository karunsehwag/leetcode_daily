class Solution {
public:
    long long backtrack(int ind,vector<vector<long long>>& vec,vector<int>& nums,int flag)
    {
        if(ind==nums.size())
            return 0;
        if(vec[ind][flag]!=-1)
            return vec[ind][flag];
        long long int old=0;
        if(flag)
        {
           old=nums[ind]+backtrack(ind+1,vec,nums,0); 
        }
        else
        {
          old=-nums[ind]+backtrack(ind+1,vec,nums,1);  
        }
        long long int newv=nums[ind]+backtrack(ind+1,vec,nums,0);
        return vec[ind][flag]=max(newv,old);
    }
    long long maximumTotalCost(vector<int>& nums) {
        int n=nums.size();
        vector<vector<long long>> vec(n+1,vector<long long>(2,-1));
        return backtrack(0,vec,nums,1);
        
    }
};