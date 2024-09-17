class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> mp;
        stringstream ss(s1);
        string word;
        while(ss >> word)
        {
            mp[word]++;
        }
        stringstream se(s2);
        while(se >> word)
        {
            mp[word]++;
        }
        vector<string> ans;
        for(auto it: mp)
        {
            if(it.second==1)
                ans.push_back(it.first);
        }
        return ans;
           
            
        
    }
};