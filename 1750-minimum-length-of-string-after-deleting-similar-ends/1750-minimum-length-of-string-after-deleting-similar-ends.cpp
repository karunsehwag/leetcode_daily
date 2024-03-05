class Solution {
public:
    int minimumLength(string s) {
        int low=0;
        int high=s.size()-1;
        while(high>low&& s[high]==s[low]&&s.size()!=1)
        {
            char ch=s[low];
            while(ch==s[low]&high>=low)
                low++;
            while(ch==s[high]&&high>=low)
                high--;
        }
        
        return high-low+1;
        
    }
};