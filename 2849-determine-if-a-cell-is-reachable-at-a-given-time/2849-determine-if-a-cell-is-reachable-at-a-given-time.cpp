class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        
        if(sx==fx&&fy==sy&&t==1)
            return 0;
     
        int minx=abs(sx-fx);
        int miny=abs(sy-fy);
        int ans=abs(minx-miny)+min(minx,miny);
        
        if(ans>t)
            return 0;
        
        return 1;
        
    }
};