class Solution {
public:
    bool check(vector<int>& quantities,int mid,int n)
    {
        int count=0;
        for(int x:quantities)
        {
            count+=(mid+x-1)/mid;
        }
        
        return count<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1,high=0;
        for(int x:quantities)
           high=max(x,high);
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(quantities,mid,n))
            {   ans=mid;
                high=mid-1;
            }
            else
            {
               
                low=mid+1;
            }
        }
        return ans;
        
    }
};