class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int> mp;
        int left=0,right=0;
        int ans=0;
        while(right<s.size())
        {
            while(mp[s[right]]>0&&right>left)
            {
                mp[s[left]]--;
                left++;
            }
            mp[s[right]]++;
           // cout<<right<<"  "<<left;
            ans=max(ans,static_cast<int>(right-left+1));
            right++;
            
            
        }
        return ans;   
    }
};