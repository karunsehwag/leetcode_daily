class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int> vec;
        for(int i=0;i<nums.size();++i)
        {
            int in= abs(nums[i]) - 1;
            cout<<in<<" ";
            if(nums[in]<0)
                vec.push_back(in+1);
            else
            {nums[in]=-nums[in];}
        }
        
        return vec;
        
    }
};