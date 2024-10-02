class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
            return arr;
        
        vector<int> vec;
        map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            vec.push_back(arr[i]);
        }
        sort(vec.begin(),vec.end());
        mp[vec[0]]=1;
        for(int i=1;i<arr.size();i++)
        {  if(vec[i]!=vec[i-1])
               mp[vec[i]]= mp[vec[i-1]]+1;
        }
        vector<int> ans;
        for(int i=0;i<arr.size();i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
        
        
    }
};