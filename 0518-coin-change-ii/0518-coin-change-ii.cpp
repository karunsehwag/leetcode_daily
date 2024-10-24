class Solution {
public:
    int fun(int in,int amount,vector<int>& coins,vector<vector<int>>& vec)
    {   if(amount==0)
           return 1;
        if(in>=coins.size()||amount<0)
            return 0;
         if(vec[in][amount]!=-1)
             return vec[in][amount];
         int take=fun(in,amount-coins[in],coins,vec);
         int nottake=fun(in+1,amount,coins,vec);
     
     return vec[in][amount]=take+nottake;
     
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> vec(coins.size(),vector<int>(amount+1,-1));
        return fun(0,amount,coins,vec);
        
    }
};