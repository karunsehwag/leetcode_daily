class Solution {
public:
    void rec(int i,int k,vector<int>& vec)
    {
        if(i>k)
            return;
        vec.push_back(i);
        i=i*10;
        for(int z=0;z<10;z++)
        {
          rec(i+z,k,vec);  
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> vec;
        int k=n;
        for(int z=1;z<10;z++)
        {
          rec(z,k,vec);  
        }
        return vec;
    }
};