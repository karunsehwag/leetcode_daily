class Solution {
public:
    int passThePillow(int n, int time) {
        
      int k=time/(n-1);
      int m=time%(n-1);
      if(k%2==0)
      {
          return m+1;
      }
        else
            return n-m;
          
    } 
};