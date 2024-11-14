class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        int i=0;
        for(int x:nums)
        {   
           
              auto it1=lower_bound(nums.begin()+i+1,nums.end(),(lower-x));
              auto it2=upper_bound(nums.begin()+i+1,nums.end(),(upper-x));
              ans+=it2-it1;
             
            i++;
        }
        return ans;
    }
};