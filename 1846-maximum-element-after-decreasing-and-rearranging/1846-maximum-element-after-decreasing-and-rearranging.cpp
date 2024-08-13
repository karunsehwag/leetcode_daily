class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        
        int k=arr.size();
        int val=0;
        arr[0]=1;
        for(int i=1;i<k;i++)
        {
          if(abs(arr[i]-arr[i-1])>1)
              arr[i]=arr[i-1]+1;
        }
        
        return arr[k-1];
        
    }
};