class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> vec;
        int in=0;
        int i=1;
        while(k>=vec.size())
        {
            if(arr.size()>in&&arr[in]==i)
            {
                i++;
                in++;
            }else
            {
              vec.push_back(i); 
              i++;
            }
        }
      return vec[k-1];  
    }
};