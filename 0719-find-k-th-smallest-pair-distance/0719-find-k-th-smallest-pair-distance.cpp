class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int maxd=nums[size-1]-nums[0];
        int low=0;
        while(maxd>low)
        {
            int mid=(maxd+low)/2;
            int count=binary(nums,mid);
            if(k>count)
                low=mid+1;
            else
                maxd=mid;
                
        }
        return low;
        
    }
    
    int binary(vector<int>& nums,int k)
    {
        int left=0,right=0;
        int count=0;
        for(int right=0;right<nums.size();right++)
        {
            while((nums[right]-nums[left])>k)
                left++;
            count+=right-left;
        }
        return count;
    }
};