class Solution {
public:
    int minimumChairs(string s) {
        int ans=0;
        int k=0;
        for(char ch:s)
        {
            if(ch=='E')
            {
                k++;
                ans=max(ans,k);
            }
            else
            {
                k--;
            }
        }
       return ans; 
    }
};