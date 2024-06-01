class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxv=INT_MIN,minv=1;
        for(int i=0;i<piles.size();i++)
        {
            maxv=max(piles[i],maxv);
            minv=min(piles[i],minv);
        }
        while(maxv>=minv)
        {
            long long int mid=(maxv+minv)/2;
            long long int total=find(piles,mid);
            if(total<=h)
                maxv=mid-1;
            else
                minv=mid+1;
        }
        return minv;    
    }
    long long int find(vector<int>& piles,int mid)
    {
        long long int sum=0;
        for(int i=0;i<piles.size();i++)
        {
            sum+=ceil((double)piles[i]/(double)mid);
        }
        return sum;
    }
};