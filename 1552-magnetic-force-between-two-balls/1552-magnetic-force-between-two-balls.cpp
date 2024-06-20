class Solution {
public:
    bool check(int mid,vector<int>& position,int m)
    {
        int count=1;
        int left=0;
        for(int i=0;i<position.size();i++)
        {
            if(abs(position[i]-position[left])>=mid)
            {
                    left=i;
             count++;}
        }
            return count>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        int high=INT_MIN,low=0;
        for(int i=0;i<position.size();i++)
        {  high=max(high,position[i]);
           low=min(low,position[i]);       
        }
        sort(position.begin(),position.end());
        while(high>=low)
        {
            int mid=low+(high-low)/2;
            if(check(mid,position,m))
            {   
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return high;
        
        
    }
};