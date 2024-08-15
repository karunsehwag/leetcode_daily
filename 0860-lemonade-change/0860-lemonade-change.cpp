class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0,ten=0,tewnty=0;
        for(int x:bills)
        {
            if(x==5)
                five++;
            if(x==10)
            {
                ten++;
                if(five>0)
                    five--;
                else 
                    return 0;
            }
            if(x==20)
            {
                if(five>0&&ten>0)
                {
                    five--;
                    ten--;
                }
                else if(five>=3)
                {
                    five-=3;
                }
                else 
                    return 0;
            }
        }
        
        return 1;
    }
};