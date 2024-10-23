class Solution {
public:
    int fun(vector<int> vec)
    {
        vec.push_back(0);
        stack<int> st;
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            while(!st.empty()&&vec[st.top()]>vec[i])
            {
                int height=vec[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                int cal=width*height;
                ans=max(cal,ans);
                
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> vec(matrix.size(),vector<int>(matrix[0].size(),0));
        for(int i=0;i<matrix.size();i++)
        {
         for(int j=0;j<matrix[0].size();j++)
         {
             if(i==0&&matrix[i][j]=='1')
                 vec[i][j]=1;
             else if(matrix[i][j]=='1')
             {
               vec[i][j]+=vec[i-1][j]+1; 
             }
         }
        }
       // for(int i=0;i<matrix.size();i++)
       //  {
       //   for(int j=0;j<matrix[0].size();j++)
       //   {
       //       cout<<vec[i][j]<<"  ";
       //   }
       //      cout<<endl;
       //  }
        int ans=0;
        for(int i=0;i<matrix.size();i++)
        {
            ans=max(ans,fun(vec[i]));
        }
     return ans;
    }
};