class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        map<double,double> mp;
        for(int x:nums1)
        {
            for(int i=1;i*i<=x;i++)
            {
                if(i*i==x)
                    mp[i]++;
                else if(x%i==0)
                {
                    mp[i]++;
                    mp[x/i]++;
                }
                
            }
        }
        long long int ans=0;
        for(int i=0;i<nums2.size();i++)
        {
            int num=nums2[i]*k;
            if(mp.find(num)!=mp.end())
            {
               ans+=mp[num]; 
            }
        }
        return ans;
        
    }
};