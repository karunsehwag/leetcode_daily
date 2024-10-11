class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int t) {
        vector<int> target=times[t];
        sort(times.begin(),times.end());
        int n=times.size();
        vector<int> chair(n);
        for(auto time:times)
        {
            for(int i=0;i<n;i++)
            {
                if(chair[i]<=time[0])
                {
                    chair[i]=time[1];
                    if(time==target) return i;
                    break;
                }
            }
        }
        return 0;
        
    }
};