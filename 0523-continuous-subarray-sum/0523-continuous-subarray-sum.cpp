class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefix=0;
        unordered_map<int,int> modseen;
        modseen[0]=-1;
        for(int i=0;i<nums.size();i++)
        {   
            prefix=(prefix+nums[i])%k;
            if(modseen.find(prefix)!=modseen.end())
            {
                if(i-modseen[prefix]>1)
                    return 1;
            }
            else
            {
                modseen[prefix]=i;
            }
        }
        
    
        return 0;
        
        
    }
};