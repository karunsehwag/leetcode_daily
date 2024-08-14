class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        
        int maxv=0;
    for(int x:left)
        maxv=max(x,maxv);
    for(int x:right)
        maxv=max(n-x,maxv);
        return maxv;
        
    }
};