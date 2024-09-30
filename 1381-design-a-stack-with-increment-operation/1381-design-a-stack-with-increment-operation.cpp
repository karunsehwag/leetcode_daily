class CustomStack {
public:
    vector<int> vec;
    int ptr=0;
    CustomStack(int maxSize) {
        
      ptr=maxSize;
    }
    
    void push(int x) {
        if(ptr>vec.size())
            vec.push_back(x);
        
    }
    
    int pop() {
        if(vec.empty())
            return -1;
        int ans=vec[vec.size()-1];
        vec.pop_back();
        return ans;
    }
    
    void increment(int k, int val) {
        
        for(int i=0;i<min(k,static_cast<int>(vec.size()));i++)
            vec[i]+=val;
        
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */