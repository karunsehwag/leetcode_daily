class SeatManager {
public:
    vector<int> vec;
    int k=0;
    SeatManager(int n) {
        vec.resize(n,0);
        
    }
    
    int reserve() {
        
        for(int i=k;i<vec.size();i++)
            if(vec[i]==0)
            {   vec[i]=1;
                k=i+1;
                return i+1;}
        
        return -1;
        
    }
    
    void unreserve(int seatNumber) {
        
        vec[seatNumber-1]=0;
        k=min(seatNumber-1,k);
        
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */