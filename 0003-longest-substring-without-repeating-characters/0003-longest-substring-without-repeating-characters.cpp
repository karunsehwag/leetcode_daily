class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int ans=0;
        int left=0,right=0;
        while(s.size()>right)
        {
            mp[s[right]]++;
          
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,static_cast<int>(right-left+1));
            right++;
        }
        return ans;
        
    }
};