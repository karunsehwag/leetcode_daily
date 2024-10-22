class Twitter {
public:
    unordered_map<int,set<int>> followmap;
    unordered_map<int,priority_queue<pair<int,int>>> news;
    int timestamp=0;
    Twitter() 
    {
        timestamp=0;
    }
    void postTweet(int userId, int tweetId) 
    {
        news[userId].push({timestamp++,tweetId});
    }
    vector<int> getNewsFeed(int userId) 
    {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        if(news.find(userId)!=news.end()) pq=news[userId];
        for(int it:followmap[userId])
        { 
            if(news.find(it)!=news.end())
            { 
            auto get=news[it];
            while(!get.empty())
            {   
                pq.push(get.top());
                get.pop();
            }
            }
        }
        int n=10;
        while(!pq.empty()&&n)
        {
            ans.push_back(pq.top().second);
            pq.pop();
            n--;
        }
        return ans;
    }
    void follow(int followerId, int followeeId)
    {
        followmap[followerId].insert(followeeId);    
    }
    void unfollow(int followerId, int followeeId)
    {
        followmap[followerId].erase(followeeId);    
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */