class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        
        vector<vector<int>> vec(ranges.size(),vector<int>(2,0));
        for(int i=0;i<ranges.size();i++)
        {  if(ranges[i]!=0)
        {
            vec[i][0]=i-1*ranges[i];
            vec[i][1]=i+ranges[i]; 
        }
        }
        sort(vec.begin(),vec.end());
        
        int count = 0;
        int currentEnd = 0;
        int farthest = 0;
        int i = 0;
         while (currentEnd < n) {
            while (i < vec.size() && vec[i][0] <= currentEnd) {
                farthest = max(farthest, vec[i][1]);
                i++;
            }

            if (farthest == currentEnd) {
                
                return -1;
            }

            currentEnd = farthest;
            count++;
        }

        return count; 
        
    }
};