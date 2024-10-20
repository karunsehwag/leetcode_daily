class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int ptr=0;
    KthLargest(int k, vector<int>& nums) {
        
        for(int x:nums)
            pq.push(x);
            ptr=k;
        
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>ptr)
            pq.pop();
        return pq.top();
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */