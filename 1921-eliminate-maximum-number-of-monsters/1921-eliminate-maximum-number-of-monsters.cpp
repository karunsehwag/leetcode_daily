class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        
        vector<int> vec(dist.size(),0);
        for(int i=0;i<dist.size();i++)
        {
            vec[i]=(dist[i]+speed[i]-1)/speed[i];
        }
        sort(vec.begin(),vec.end());
        for(int i=0;i<dist.size();i++)
        {
            if(i>=vec[i])
               return i;
        }
        
        return dist.size();
    }
};