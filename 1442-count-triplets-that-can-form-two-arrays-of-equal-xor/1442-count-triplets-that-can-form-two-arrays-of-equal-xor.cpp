class Solution {
public:
    int countTriplets(vector<int>& arr) {
        
        vector<int> vec(arr.size()+1,0);
        for(int i=0;i<arr.size();i++)
        {
            vec[i+1]=vec[i]^arr[i];
         
        }
        int sum=0;
        for(int i=0;i<vec.size();i++)
        {
            for(int j=i+1;j<vec.size();j++)
            {
                if(vec[i]==vec[j])
                    sum+=j-i-1;
            }
        }
            
      return sum;  
    }
};