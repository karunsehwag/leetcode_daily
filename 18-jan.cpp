class Solution {
public:
    
    int climbStairs(int n) {
        int n1=1,n2=2,ans=0;
        if(0>=n)
         return ans;
        else if(n==1)
         return 1;
        else if(n==2)
         return 2;
        for(int i=3;n>=i;i++)
        {
            ans=n1+n2;
            n1=n2;
            n2=ans;
            
        } 
        return ans;
    }
};