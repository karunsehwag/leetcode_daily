class Solution {
public:
    void backtrack(vector<int> vec,vector<vector<int>>& ans,int i,vector<int> nums)
    {
        ans.push_back(vec);
        for(int j=i;j<nums.size();j++)
        { vec.push_back(nums[j]);
          backtrack(vec,ans,j+1,nums);
         vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
     vector<int> vec;
     vector<vector<int>> ans;
     backtrack(vec,ans,0,nums);
     return ans;
    }
};