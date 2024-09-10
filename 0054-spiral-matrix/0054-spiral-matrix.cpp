class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int i=0,j=0;
        int k=matrix.size(),m=matrix[0].size();
        while(i<k&&j<m)
        {
            for(int o=j;o<m;o++)
                ans.push_back(matrix[i][o]);
            i++;
            for(int o=i;o<k;o++)
                ans.push_back(matrix[o][m-1]);
            m--;
            if(i<k)
            {
            for(int o=m-1;o>=j;o--)
                ans.push_back(matrix[k-1][o]);
            k--;
            }   
            
            if(j<m)
            { 
            for(int o=k-1;o>=i;o--)
                ans.push_back(matrix[o][j]);
            j++;
            }    
        }
        return ans;
        
    }
};