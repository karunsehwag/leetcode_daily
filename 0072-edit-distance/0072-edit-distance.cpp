class Solution {
public:
    int rec(int i,string word1,int j,string word2,vector<vector<int>>& vec)
    {
        if(i>=word1.size())
            return word2.size()-j;
        if(j>=word2.size())
            return word1.size()-i;
        if(vec[i][j]!=-1)
            return vec[i][j];
        if(word1[i]==word2[j])
        { 
            return vec[i][j]=rec(i+1,word1,j+1,word2,vec);
        }
        else
        {
     
        int rep=rec(i+1,word1,j+1,word2,vec);
        int del=rec(i+1,word1,j,word2,vec);
        int insert=rec(i,word1,j+1,word2,vec);
        return vec[i][j]=1+min(rep,min(del,insert));
            
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> vec(word1.size()+1,vector<int>(word2.size()+1,-1));
        
        return rec(0,word1,0,word2,vec);
        
    }
};