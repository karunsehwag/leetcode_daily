class Solution {
public:
    int dp(int in,vector<int>& coins,int amount,vector<vector<int>>& vec)
    {   if(amount==0)
           return 0;
        if(in>=coins.size()||amount<0)
        {
            return 100001;
        }
     if(vec[in][amount]!=-1)
         return vec[in][amount];
     int take=1+dp(in,coins,amount-coins[in],vec);
     int notake=dp(in+1,coins,amount,vec);
     return vec[in][amount]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
     vector<vector<int>> vec(coins.size(),vector<int>(amount+1,-1));
     int val=dp(0,coins,amount,vec);
     return val==100001?-1:val;
        
    }
};