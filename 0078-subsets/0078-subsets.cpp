class Solution {
public:
    void backtrack(vector<int> vec,vector<vector<int>>& ans ,vector<int> nums ,int i)
    {
        ans.push_back(vec);
        for(int j=i;j<nums.size();j++)
        {
            vec.push_back(nums[j]);
            backtrack(vec,ans,nums,j+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> vec;
        vector<vector<int>> ans;
        backtrack(vec,ans,nums,0);
        return ans;
    }
};