class Solution {
public:
    int maximumSwap(int num) {
        vector<int> nums;
        int in1=-1,in2=-1,maxid=-1,maxv=INT_MIN;
        int temp=num;
          while (temp > 0) {
            nums.push_back(temp % 10);
            temp /= 10;
        }
        reverse(nums.begin(),nums.end());
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(nums[i]>maxv)
            {
                maxv=nums[i];
                maxid=i;  
            }
            else if(maxv>nums[i])
            {
                in1=i;
                in2=maxid;
            }
            
        }
        if(in1!=-1)
            swap(nums[in1],nums[in2]);
        int ans=0;
        for(int x:nums)
            ans=ans*10+x;
        
        return ans;
        
    }
};