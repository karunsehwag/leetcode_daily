class Solution {
public:
    bool check(vector<int>& time,long long mid,int n)
    {
        long long  count=0;
        for(auto x:time)
        {
            count += mid/x;
            if(count>=n)
                return true;
        }
        return  false;
    }
    long long minimumTime(vector<int>& time, int n) {
        long long  low=1,high=1e14;
        
        long long  ans=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(check(time,mid,n))
            {
               ans=mid;
               high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;      
    }
};