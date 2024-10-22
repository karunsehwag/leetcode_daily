class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> freq;
        int ans=0;
        for(char ch:tasks)
            freq[ch]++;
        priority_queue<int> pq;
        for(auto it:freq)
            pq.push(it.second);
        while(!pq.empty())
        {   
            int cycle=n+1;
            vector<int> store;
            int task=0;
            while(cycle--&&!pq.empty())
            {   if(pq.top()>1)
                  store.push_back(pq.top()-1);
                pq.pop(); 
                task++;
            }
            for(int x:store)
                pq.push(x);
            ans+=pq.empty()?task:n+1;
            
        }
        return ans;
    }
};