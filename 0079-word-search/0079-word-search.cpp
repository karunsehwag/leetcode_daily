class Solution {
public:
    bool dp(int i,int j,vector<vector<char>>& board,string& word,int in,vector<vector<int>>& vis)
    {
        if(in>=word.size()-1)
            return true;
        vector<int> vec={-1,0,1,0,-1};
        in++;
        for(int k=1;k<vec.size();k++)
        {   
            int row=i+vec[k-1];
            int col=j+vec[k];
            if(row>=0&&row<board.size()&&col>=0&&col<board[0].size()&&board[row][col]==word[in]&&vis[row][col]==0)
            {   
                //cout<<word[in]<<" "<<in<<endl;
                vis[row][col]=1;
                if(dp(row,col,board,word,in,vis))
                    return true;
                vis[row][col]=0;
                    
            }
            
        }
        // cout<<"**********************"<<endl;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {  vector<vector<int>> vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {   
                if(word[0]==board[i][j])
                {   
                    vis[i][j]=1;
                    if(dp(i,j,board,word,0,vis))
                        return true;
                    vis[i][j]=0;
                    
                 }
            }
        }
        return false;
        
    }
};