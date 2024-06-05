class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> vec(n,vector<int>(26,0));
        int i=0;
        for(string x:words)
        {   
            for(char ch:x)
            {
                vec[i][ch-'a']++;
            }
            i++;
        }
        vector<string> ans;
        for(int j=0;j<26;j++)
        {  int val=INT_MAX;
            for(int i=0;i<n;i++)
            {
                val=min(val,vec[i][j]);
            }
         while(val>0)
         {
         char ch = 'a' + j; 
        std::string str(1, ch); 
         ans.push_back(str);
             val--;
             
         }
        }
        
        
        return ans;
        
    }
};