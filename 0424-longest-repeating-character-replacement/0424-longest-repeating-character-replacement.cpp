class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0;
        int ans=0,maxi=0;
        unordered_map<char,int> mp;
        while(s.size()>right)
        {
            mp[s[right]]++;
            maxi=max(maxi,mp[s[right]]);
            while(right-left+1-maxi>k)
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