class Solution {
public:
    void reverseString(vector<char>& s) {
    int siz=s.size();
        siz=siz-1;
    int i=0;
        while(siz>=i)
        {
            swap(s[i],s[siz]);
            i++;
            siz--;
            
        }
        
    }
};