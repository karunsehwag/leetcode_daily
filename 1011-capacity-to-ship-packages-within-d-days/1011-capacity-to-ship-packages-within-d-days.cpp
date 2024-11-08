class Solution {
public:
    bool check(vector<int>& weights,int mid,int days)
    {
        int count=1;
        int sum=0;
        for(int x:weights)
        {
       
         if (x > mid|| count > days){ 
                return false;
            }
         sum+=x;
         if(sum>mid)
         {
             count++;
             sum=x;
         }
        }
 
        return days>=count;         
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=1e9;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(check(weights,mid,days))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};