class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        
        
        sort(nums.begin(),nums.end());
        vector<int> vec((nums[nums.size()-1]-nums[0])+1,0);
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                vec[nums[j]-nums[i]]++;
            }
        }
        int count=0;
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            count+=vec[i];
            if(count>=k)
                return i;
        }
        
        
        return -1;
        
    }
};