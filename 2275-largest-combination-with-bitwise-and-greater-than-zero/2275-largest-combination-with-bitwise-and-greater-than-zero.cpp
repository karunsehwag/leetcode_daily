class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        
        vector<int> vec(32,0);
        int ans=0;
        for(int it:candidates)
        {
            int i=0;
            while(it)
            {
                if(it%2)
                {
                   vec[i]++;
                   ans=max(vec[i],ans);
                }
                i++;
                it=it/2;
            }
        }
        return ans; 
    }
};