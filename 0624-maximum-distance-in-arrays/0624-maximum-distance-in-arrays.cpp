class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(),arrays.end());
        int minv=INT_MAX,maxv=INT_MIN;
        for(int i=1;i<arrays.size();i++)
        {
            minv=min(minv,arrays[i][0]);
            maxv=max(maxv,arrays[i][arrays[i].size()-1]);
        }
        
        int ans=abs(maxv-arrays[0][0]);
        int ans1=abs(minv-arrays[0][arrays[0].size()-1]);
        return max(ans,ans1);
        
    }
};