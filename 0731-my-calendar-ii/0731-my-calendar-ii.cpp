class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> overlap;
    MyCalendarTwo() {
        
    }
    bool book(int start, int end)  
    {
        for(pair<int,int> booking: overlap)
        {
            if(doesoverlap(booking.first,booking.second,start,end))
                return false;
        }
        
        for(pair<int,int> booking: bookings)
        {
            if(doesoverlap(booking.first,booking.second,start,end))
            {
                overlap.push_back(getoverlap(booking.first,booking.second,start,end));
            }
        }
        bookings.push_back({start,end});
        return true;
        
    }
        private:
        
        bool doesoverlap(int start1,int end1, int start2, int end2)
        {
            return max(start1,start2)<min(end1,end2);
        }
        
        pair<int,int> getoverlap(int start1,int end1,int start2,int end2)
        {
            return {max(start1,start2),min(end1,end2)};
        }
        
        
    
};

