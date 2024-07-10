class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(string it:logs)
        {
            if(it=="../"&&count>0)
            {
                count--;
            }
            else if(it=="./")
            {
                
            }
            else if(it!="./"&&it!="../")
            {
                count++;
            }
        }
        return count;
    }
};