class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> vec;
        if(n*m!=original.size())
            return vec;
        int count=0;
        vector<int> temp;
        for(int i=0;i<original.size();i++)
        {
            if(count==n)
            {
                vec.push_back(temp);
                temp.clear();
                count=0;
            }
            temp.push_back(original[i]);
            count++;
            
        }
        vec.push_back(temp);
        return vec;
    }
};