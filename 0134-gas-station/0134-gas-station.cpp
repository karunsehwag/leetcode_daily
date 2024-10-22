class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int total=0,totalgas=0,totalcount=0,in=0;
        for(int i=0;i<gas.size();i++)
        {
            
            totalgas+=gas[i];
            totalcount+=cost[i];
            total+=gas[i]-cost[i];
            if(0>total)
            {
                total=0;
                in=i+1;
            }     
        }
        if(totalgas>=totalcount)
            return in;
        return -1;    
    }
};