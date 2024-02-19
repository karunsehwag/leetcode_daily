class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) 
    {
        vector<int> meet(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> usedr;
        priority_queue<int,vector<int>,greater<int>> unusedr;
        for(int i=0;i<n;i++)
        {
            unusedr.push(i);
        }
        sort(meetings.begin(),meetings.end());
        for(auto meets:meetings)
        {
            int start=meets[0],end=meets[1];
            while(!usedr.empty()&&usedr.top().first<=start)
            {
                int room =usedr.top().second;
                usedr.pop();
                unusedr.push(room);
            }
            if(!unusedr.empty())
            {
                int room=unusedr.top();
                unusedr.pop();
                usedr.push({end,room});
                meet[room]++;
            }
            else
            {
                auto[rt,r]=usedr.top();
                usedr.pop();
                usedr.push({rt+end-start,r});
                meet[r]++;
            }
        }
        int mc=0,mcm=0;
        for(int i=0;i<n;i++)
        {
            if(meet[i]>mc)
            {
                mc=meet[i];
                mcm=i;
            }
        }
        return mcm;
        
    }
};