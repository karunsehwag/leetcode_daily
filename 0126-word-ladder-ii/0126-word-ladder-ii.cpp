class Solution {
public:
    unordered_map<string,int> map;
    vector<vector<string>> ans;
    string b;
    void dfs(string word,vector<string>& seq)
    {
        if(word==b)
        {
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return ;
        }
        int steps=map[word];
        int size=word.size();
        for(int i=0;i<size;i++)
        {
            char orignal=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                word[i]=ch;
                if(map.find(word)!=map.end()&&map[word]+1==steps)
                {
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=orignal;
        }
    }
    vector<vector<string>> findLadders(string beginword, string endword, vector<string>& wordlist) {
        queue<string> q;
        q.push({beginword});
        int size=beginword.size();
        b=beginword;
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        st.erase(beginword);
        map[beginword]=1;
        while(!q.empty())
        {
            string word=q.front();
            int steps=map[word];
            q.pop();
            if(word==endword)
                break;
            
            for(int i=0;i<size;i++)
            {
                char orignal=word[i];
                for(char ch='a';ch<='z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word});
                        st.erase(word);
                        map[word]=steps+1;
                    }
                }
                word[i]=orignal;
            }
        }
        if(map.find(endword)!=map.end())
        {
            vector<string> seq;
            seq.push_back(endword);
            dfs(endword,seq);
        }
        
        return ans;
        
    }
};