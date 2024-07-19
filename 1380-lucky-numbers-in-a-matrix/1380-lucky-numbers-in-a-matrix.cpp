class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> vec;
        vector<int> ans;
       int rmin=INT_MIN,cmax=INT_MAX;
        for(int k=0;k<matrix.size();k++)
        {   
             int val=INT_MAX;
            for(int m=0;m<matrix[0].size();m++)
            {
                if(val>matrix[k][m])
                {
                    val=matrix[k][m];
                }
            }
         rmin=max(rmin,val);
        }
        cout<<rmin;
         for(int k=0;k<matrix[0].size();k++)
        {   
             int val=INT_MIN;
            for(int m=0;m<matrix.size();m++)
            {
                if(val<matrix[m][k])
                {
                    val=matrix[m][k];
                }
            }
         cmax=min(cmax,val);
        }
       
        if(rmin==cmax)
            return {rmin};
        
      return {};  
    }
};