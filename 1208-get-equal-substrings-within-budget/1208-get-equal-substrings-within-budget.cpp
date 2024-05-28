class Solution {
public:
    int equalSubstring(string s, string t, int cost) 
    {
        vector<int> vec(s.size(),0);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            vec[i]=abs(s[i]-t[i]);
        }
        stack<int> st;
        int sum=0;
        int ans=0;
        int left=0;
        for(int i=0;i<n;i++)
        {
            sum+=vec[i];
            while(sum>cost&&i>=left)
            {
                sum=sum-vec[left];
                left++;
            }
            ans=max(ans,i-left+1);
        }
         
        
        
        return ans;
        
        
        
    }
};