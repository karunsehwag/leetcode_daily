class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vec;
        for(string str:timePoints)
        {
            int time=((str[0]-'0')*10+(str[1]-'0'))*60+((str[3]-'0')*10+(str[4]-'0'));
            time=time%1440;
            vec.push_back(time);
        }
        sort(vec.begin(),vec.end());
        int ans=INT_MAX;
        for(int i=1;i<vec.size();i++)
        {
            ans=min(vec[i]-vec[i-1],ans);
        }
        return min(ans,1440-vec[vec.size()-1]+vec[0]);
    }
};