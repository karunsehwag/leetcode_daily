class Solution {
public:
    bool check(int mid,vector<int>& bloom,int m,int k)
    {
        int count=0;
        int ch=0;
        for(int i=0;i<bloom.size();i++)
        {
            if(mid>=bloom[i])
            {
                count++;
                if(count==k)
                {
                    ch++;
                        count=0;
                }
            }
            else
                count=0;
        }
        return ch>=m;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        if ((long long)m * k > bloom.size()) return -1;
        int high=INT_MIN;
        int low=INT_MAX;
        for(int i=0;i<bloom.size();i++)
        {
            high=max(bloom[i],high);
            low=min(bloom[i],low);
            
        }
        while(high>=low)
        {
            int mid=low+(high-low)/2;
            if(check(mid,bloom,m,k))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
        
    }
};