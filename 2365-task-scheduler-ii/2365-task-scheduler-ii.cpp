class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<int,long long> mp;
        long long ans=0;
        for(int i=0;i<tasks.size();i++)
        {  
           if(mp.find(tasks[i])!=mp.end())
           {
            if(ans<mp[tasks[i]]+space+1)
               ans=mp[tasks[i]]+space+1;
               
           }  
            mp[tasks[i]]=ans;
            ans++;    
        }
        return ans;
        
    }
};