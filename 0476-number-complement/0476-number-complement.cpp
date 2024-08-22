class Solution {
public:
    int findComplement(int num) {
        int count=0;
        int z=num;
        while(z)
        {
            z=z/2;
            count++;
        }
        return pow(2,count)-num-1;
        
    }
};