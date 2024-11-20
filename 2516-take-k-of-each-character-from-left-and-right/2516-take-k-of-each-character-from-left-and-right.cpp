class Solution {
public:
    int takeCharacters(string s, int k) {
        
        vector<int> count(3,0);
        int n=s.size();
        for(char c:s)
            count[c-'a']++;
        
        for(int i=0;i<3;i++)
        {
            if(count[i]<k) return -1;
        }
        
        vector<int> window(3,0);
        int left=0,maxw=0;
        
        for(int right=0;right<n;right++)
        {
            window[s[right]-'a']++;
            while(left<=right&&(count[0]-window[0]<k||count[1]-window[1]<k||count[2]-window[2]<k))
            {
                window[s[left]-'a']--;
                left++;
            }
            
            maxw=max(maxw,right-left+1);
        }
        
        return n-maxw;
        
    }
};