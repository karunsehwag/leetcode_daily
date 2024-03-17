class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inv, vector<int>& ne) {
        vector<vector<int>> vec;
        int n=inv.size();
        int i=0;
        while(i<n&&inv[i][1]<ne[0])
        {
            vec.push_back(inv[i]);
            i++;
        }
        while(i<n&& ne[1]>=inv[i][0])
        {
            ne[0]=min(ne[0],inv[i][0]);
            ne[1]=max(ne[1],inv[i][1]);
            i++;
        }
        vec.push_back(ne);
        while(i<n)
        {
            vec.push_back(inv[i]);
            i++;
        }
        return vec;
    }
};