class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<int> vec(26,0);
        for(char ch:allowed)
        {
            vec[ch-'a']++;
        }
        int count=0;
        for(string str:words)
        {
            vector<int> ans(26,0);
            for(char ch:str)
            {
                ans[ch-'a']++;
            }
            count++;
            for(int i=0;i<26;i++)
            {
                if(ans[i]>0&&vec[i]==0)
                {
                    count--;
                    break;
                }
            }
        }
        return  count;
        
        
    }
};