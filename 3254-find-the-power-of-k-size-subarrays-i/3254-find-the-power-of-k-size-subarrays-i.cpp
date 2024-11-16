#pragma GCC optimize ("O3")

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n=nums.size();
        int left=0;
        int right=k-1;
        vector<int> result;
        while(right<n)
        {
            bool iscon=true;
            for(int i=left+1;i<=right;i++)
            {
                if(nums[i]-nums[i-1]!=1)
                {
                    result.push_back(-1);
                    iscon=false;
                    break;
                }
            }
            if(iscon)
            {
                result.push_back(nums[right]);
            }
            left++;
            right++;
        }
        return result;
    }
};