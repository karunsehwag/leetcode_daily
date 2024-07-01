class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int i=0;
        for(int x:arr)
        {
            if(x%2)
                i++;
            else
                i=0;
            if(i==3)
                return 1;
        }
        return 0;
        
    }
};