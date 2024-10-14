class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int window=cardPoints.size()-k;
        int sum=0;
        int tsum=0;
        for(int x:cardPoints)
            tsum+=x;
        for(int i=0;i<window;i++)
            sum+=cardPoints[i];
        int ans=INT_MAX;
        ans=min(sum,ans);
         for(int i=window;i<cardPoints.size();i++)
         {
             sum+=cardPoints[i]-cardPoints[i-window];
             ans=min(sum,ans);
         }
        return tsum-ans;
        
    }
};