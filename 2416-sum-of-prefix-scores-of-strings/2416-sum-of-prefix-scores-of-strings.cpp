class Trienode {
    public:
       char ch;
       int count;
       Trienode* children[26];
       Trienode(char c)
       {
           ch=c;
           count=0;
           for(int i=0;i<26;i++)
           {
               children[i]=nullptr;
           }
       }
};
class trie {
    public:
       Trienode* root;
       trie()
       {
           root= new Trienode('\0');
       }
    void insert(string word)
    {
        Trienode* node=root;
        for(char ch:word)
        {
            int idx=ch-'a';
            if(node->children[idx]==nullptr)
            {
                node->children[idx]=new Trienode(ch);
            }
            node=node->children[idx];
            node->count++;
        }
    }
    int prefixsum(string word)
    {
        Trienode* node=root;
        int sum=0;
        for(char ch:word)
        {
            int idx=ch-'a';
            node=node->children[idx];
            sum+=node->count;
        }
        return sum;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        trie t;
        for(string word:words)
        {
            t.insert(word);
        }
        vector<int> ans;
        for(string word:words)
        {
            int count=t.prefixsum(word);
            ans.push_back(count);
        }
        return ans;
        
    }
};