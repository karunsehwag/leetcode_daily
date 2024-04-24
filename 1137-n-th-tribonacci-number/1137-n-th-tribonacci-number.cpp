class Solution {
public:
    int tribonacci(int n) {
        int i=0;
        int j=1;
        int k=1;
        if(n==0)
            return 0;
        if(n==1||n==2)
            return 1;
        int ans=0;
        for(int o=3;o<=n;o++)
        {
            ans=i+j+k;
            i=j;
            j=k;
            k=ans;
           
        }
        return ans;
        
    }
};