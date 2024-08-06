class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> vec(26,0);
        
        for(char ch:word)
        {
           vec[ch-'a']++; 
        }
        
        sort(vec.rbegin(),vec.rend());
       
        int count=0;
        for(int i=0;i<26;i++)
        {
            if(8>i)
                count+=vec[i];
            else if(16>i)
                count+=vec[i]*2;
            else if(24>i)
                count+=vec[i]*3;
            else if(26>i)
                count+=vec[i]*4;
           cout<<count<<" ";
        }
        
       return count; 
    }
};