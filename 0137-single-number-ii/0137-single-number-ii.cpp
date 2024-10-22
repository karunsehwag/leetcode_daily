class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> vec(33,0);
        
        for(int num:nums)
        {   int i=0;
            if(num<0)
                vec[32]+=1;
            while(num)
            {
                vec[i]+=num%2;
                num/=2;
                i++;
            }
        }
        long long ans=0;
        for(int i=0;i<32;i++)
        {   if(vec[i]%3)
               ans+=pow(2,i);
        }
        if(vec[32]%3)
            ans=-1*ans;
        return static_cast<int>(ans);
    }
};