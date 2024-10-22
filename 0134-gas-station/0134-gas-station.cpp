class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
       for(int in=0;in<gas.size();in++)
       {
       int remain=gas[in]-cost[in];
       int ptr=(in+1)%gas.size();
       while(ptr!=in)
       {  
           if(0>=remain)
               break;
           remain+=gas[ptr]-cost[ptr];
           ptr=(ptr+1)%gas.size();   
       }
           if(ptr==in&&remain>=0)
               return in;
       }   
        return -1;
    }
};