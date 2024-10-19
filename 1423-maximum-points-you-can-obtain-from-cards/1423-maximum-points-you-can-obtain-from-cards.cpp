class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        int n=cardPoints.size()-1;
        k--;
        int i=0;
        int ans=sum;
        while(k>-1)
        {
            sum+=cardPoints[n-i]-cardPoints[k];
            k--;
            i++;
            ans=max(sum,ans);
        }
        
        return ans;
    }
};