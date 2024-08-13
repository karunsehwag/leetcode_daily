class Solution {
public:
    void rec(int i,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& vec)
    {
        
          if(0==target)
          {ans.push_back(vec);
           return ;
          }
        if(i>=candidates.size()||0>target)
            return;
      
  
    
        
         vec.push_back(candidates[i]);
         rec(i+1,candidates,target-candidates[i],ans,vec);
         vec.pop_back();
         while (i+1 <candidates.size() && candidates[i] == candidates[i + 1]) 
             i++;
         rec(i+1,candidates,target,ans,vec);
        
        
        
        
        return ;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        rec(0,candidates,target,ans,vec);
        return ans;
        
        
    }
};