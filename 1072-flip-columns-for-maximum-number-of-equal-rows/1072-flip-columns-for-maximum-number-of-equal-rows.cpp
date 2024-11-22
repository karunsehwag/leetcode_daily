class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        
        int numcol=matrix[0].size();
        int maxi=0;
        for(auto& currow:matrix)
        {
            vector<int> flip(numcol);
            int id=0;
            for(int col=0;col<numcol;col++)
            {
                flip[col]=1-currow[col];
            }
            
            for(auto& comp:matrix)
            {
                if(comp==currow||comp==flip)
                    id++;
            }
            maxi=max(id,maxi);
        }
        
        return maxi;
        
    }
};