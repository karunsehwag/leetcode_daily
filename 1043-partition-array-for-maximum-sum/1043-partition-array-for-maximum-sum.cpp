
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) 
    {
        vector<int> vec(arr.size(),-1);
        return backtrack(arr,k,0,vec);
        
    }
    int backtrack(vector<int>& arr,int k,int ind,vector<int>&vec)
    {   if(ind>=arr.size())
        return 0;
        if(vec[ind]!=-1)
            return vec[ind];
        int sum=INT_MIN;
        int val=INT_MIN;
        int n=arr.size();
        int h=min(ind+k,n);
        for(int i=ind;i<h;i++)
        {
          val=max(val,arr[i]);
          int z=val*(i-ind+1)+backtrack(arr,k,i+1,vec);
          sum=max(z,sum);
          vec[ind]=sum;
        }
        return sum;
    }
};