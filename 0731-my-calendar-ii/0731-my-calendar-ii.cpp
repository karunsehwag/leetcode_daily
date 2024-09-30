class MyCalendarTwo {
public:
    map<int,int> bookingcount;
    int maxover;
    MyCalendarTwo() 
    {
     maxover=2;   
    }
    
    bool book(int start, int end) 
    {
        
        bookingcount[start]++;
        bookingcount[end]--;
        int overlapped=0;
        for(pair<int,int> bookings: bookingcount)
        {
            
            overlapped+=bookings.second;
            if(overlapped>maxover)
            {
                bookingcount[start]--;
                bookingcount[end]++;
                
                if(bookingcount[start]==0)
                    bookingcount.erase(start);
                if(bookingcount[end]==0)
                    bookingcount.erase(end);
                
                return false;
            }
        }
       
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */