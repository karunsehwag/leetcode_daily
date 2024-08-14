class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
       sort(arr.begin(),arr.end());
       vector<vector<int>> vec(arr.size(),vector<int>(2,0));
        for(int i=0;i<arr.size();i++)
        {
            vec[i][1]=arr[i];
            int count=0;
            while(arr[i]>0)
            {
                if(arr[i]%2)
                    count++;
                arr[i]=arr[i]/2;
            }
            vec[i][0]=count;
            
        }
        sort(vec.begin(),vec.end());
        vector<int> ans;
        for(int i=0;i<vec.size();i++)
            ans.push_back(vec[i][1]);
        
        
        return ans;
        
    }
};