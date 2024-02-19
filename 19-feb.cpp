class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long int k=1;
        while(n>=k)
        {
          if(n==k)
            return 1;
           k=k*2; 
        }    
        return 0;
    }
};