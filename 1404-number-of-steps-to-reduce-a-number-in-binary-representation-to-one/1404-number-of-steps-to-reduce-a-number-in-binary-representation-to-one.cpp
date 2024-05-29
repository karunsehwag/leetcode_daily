class Solution {
public:
    int numSteps(string s) {
        int n=s.size();
        vector<int> vec(n+1,0);
        for(int i=0;i<n;i++)
        {
            vec[i]=s[i]-'0';
        }
        n=n-1;
        int count=0;
        while(n>0)
        {
            if(vec[n]==0)
            {vec.pop_back();
            n--;}
            else
            {   int m=n;
                while(m>=0)
                {
                    if(vec[m]==1)
                       vec[m]=0;
                    else
                    {vec[m]=1;
                     break;}
                    m--;
                    
                    
                     }
             if(m==-1)
             {vec.insert(vec.begin(), 1);
             n++;}
             
                    
            }
            count++;
        }
       
       return count; 
    }
};