class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int val=start^goal;
        int ans=0;
        while(val)
        {
            if(val%2)
                ans++;
            val=val/2;
        }
        return ans;
    }
};