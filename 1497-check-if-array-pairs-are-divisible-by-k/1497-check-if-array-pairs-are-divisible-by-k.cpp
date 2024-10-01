class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> vec(k,0);
        
        for(int it:arr)
        {
            vec[(it%k+k)%k]++;
        }
        if(vec[0]%2==1)
            return false;
        for(int i=1;i<=k/2;i++)
        { cout<<i<<endl;
            if(i==k-i)
            {
                if(vec[i]%2!=0)
                    return false;
               
            }
          else
                {
                    if(vec[i]!=vec[k-i])
                        return false;
                }
        }
        return true;
    }
};