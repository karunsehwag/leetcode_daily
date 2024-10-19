class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        int left=0,right=0;
        for(char c:t)
        {
            mp[c]++;
        }
        int count=t.size(),minl=INT_MAX,st=0;
        while(s.size()>right)
        {
            if(mp[s[right]]-->0)
                count--;
            
            while (count == 0) {
                if (right - left+1< minl) {
                    minl = right - left+1;
                    st = left;  
                }
                
//                 mp[s[left]]++;
                if (mp[s[left]]++ == 0) {
                    count++; 
                }
                left++;  
            }
            right++;
        }
        string ans;
        return ans=minl==INT_MAX?"":s.substr(st,minl);
        
    }
};