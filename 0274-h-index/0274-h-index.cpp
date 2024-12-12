class Solution {
public:
    bool binary(vector<int> citations,int mid)
    {
        int count=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=mid)
                count++;
            if(count>=mid) return true;
        }
        
        return false;
    }
    int hIndex(vector<int>& citations) {
        int low=0;
        int high=1000;
        int ans=-1;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(binary(citations,mid))
            {
                ans=mid;
                low=mid +1;
            }
            else
                high=mid-1;
        }
        return ans;
        
    }
};