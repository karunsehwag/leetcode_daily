class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum=mean*(n+rolls.size());
        for(int it:rolls)
        {
            sum-=it;
        }
       
       int dif=sum/n;
        if(n>sum||dif>6||(dif==6&&sum%n))
            return {};
       vector<int> ans;
        for(int i=0;i<n;i++)
        {
           ans.push_back(dif);
           sum-=dif;
        }
        for(int i=0;i<n;i++)
        {   if(sum==0)
               break;
            ans[i]+=1;
            sum--;
        }
        return ans;
        
        
    }
};