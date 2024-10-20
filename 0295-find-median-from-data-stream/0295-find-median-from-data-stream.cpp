class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>> mp;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(pq.empty()||num<=pq.top())
            pq.push(num);
        else
            mp.push(num);  
        
        if(pq.size()>(mp.size()+1))
        {
            mp.push(pq.top());
            pq.pop(); 
        }
        else if(mp.size()>pq.size())
        {
            pq.push(mp.top());
            mp.pop();
        }
            
    }
    
    double findMedian() {
  
        if(pq.size()==mp.size())
            return (pq.top()+mp.top())/2.0;
        return pq.top();
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */