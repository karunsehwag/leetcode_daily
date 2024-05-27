class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n+1,0);
        for(int i=0;i<n;i++)
        {
            vec[min(nums[i],n)]++;
        }
        int count=0;
        for(int i=n;i>=0;i--)
        {
            count+=vec[i];
            if(count==i)
                return count;
        }
      return -1;  
    }
};