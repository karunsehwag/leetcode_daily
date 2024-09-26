class MyCalendar {
public:
    vector<pair<int,int>> vec;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        if(vec.empty())
        {
            vec.push_back({start,end});
            return true;
        }
        int low=0,high=vec.size()-1;
        while(high>=low)
        {
            int mid=(low+high)/2;
            if(vec[mid].first>start)
                high=mid-1;
            else
                low=mid+1;
        }
        if(low>0&&vec[low-1].second>start)
            return false;
        if(low<vec.size()&&end>vec[low].first)
            return false;
        vec.insert(vec.begin()+low,{start,end});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */