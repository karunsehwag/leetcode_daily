class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        if(k>=arr.size())
        {
            int maxv=0;
            for(int i=0;i<arr.size();i++)
                maxv=max(maxv,arr[i]);
            return maxv;
        }
        int val=arr[0];
        int count=0;
        for(int i=1;i<arr.size();i++)
        {
            if(val>arr[i])
            {
                count++;
            }
            else
            {
                val=arr[i];
                count=1;
            }
            
            if(count==k)
                return val;
        }
        
        return val;
        
    }
};