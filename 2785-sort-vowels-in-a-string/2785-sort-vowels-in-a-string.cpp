class Solution {
public:
    string sortVowels(string s) {
        
        vector<int> vec;
        priority_queue<char,vector<char>,greater<char>> q;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
               vec.push_back(i); 
                q.push(s[i]);
            }
        }
        for(int i=0;i<vec.size();i++)
        {
            s[vec[i]]=q.top();
            q.pop();
            
        }
        
        return s;
        
    }
};