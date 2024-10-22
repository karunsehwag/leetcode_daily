class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        int tank = 0, startIdx = 0;
        for(int i = 0; i < n; i++) 
        {
            totalGas += gas[i];
            totalCost += cost[i];
            tank += gas[i] - cost[i];
            // tank gas becomes negative, reset startIdx and tank
            if(tank < 0) 
            {
                startIdx = i + 1;
                tank = 0;
            }
        }

        if(totalGas >= totalCost) 
            return startIdx;
        else
            return -1;
    }
};