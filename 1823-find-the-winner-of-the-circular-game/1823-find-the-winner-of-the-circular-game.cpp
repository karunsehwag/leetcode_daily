class Solution {
public:
    int findTheWinner(int n, int k) {
    queue<int> vec;
        for(int i=1;i<=n;i++)
            vec.push(i);
        int m=1;
        while(vec.size()!=1)
        {
           if(m!=k)
           {
                m++;
                vec.push(vec.front());
                vec.pop();
              
           }
            else
            {  
               vec.pop();
               m=1;
            }
            
        }
      return vec.front();
        
    }
};