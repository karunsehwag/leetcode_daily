class Solution {
public:
    int ladderLength(string startword, string endword, vector<string>& wordlist) {
        queue<pair<string,int>> q;
        q.push({startword,1});
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        st.erase(startword);
        while(!q.empty())
        {
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==endword)
                return steps;
            for(int i=0;i<word.size();i++)
            {
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]=orignal;
            }
        }
        return 0;
    }
};