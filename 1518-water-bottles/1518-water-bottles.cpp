class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int k=0;
        while((numBottles+k)>=numExchange)
        {
            ans+=numBottles;
            int val=(numBottles+k)/numExchange;
            k=(numBottles+k)%numExchange;
            numBottles=val;
            
        }
        ans+=numBottles;
        return ans;
        
    }
};