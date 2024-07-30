class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        vector<int> count_a(n,0);
        vector<int> count_b(n,0);
        int b_count=0;
        
        for(int i=0;i<n;i++)
        {
            count_b[i]=b_count;
            if(s[i]=='b') b_count++;
        }
        int a_count=0;
        for(int i=n-1;i>=0;i--)
        {
            count_a[i]=a_count;
            if(s[i]=='a') a_count++;
        }
        
        int ans=n;
        
        for(int i=0;i<n;i++)
        {
            ans=min(ans,count_a[i]+count_b[i]);
        }
        return ans;
    }
};