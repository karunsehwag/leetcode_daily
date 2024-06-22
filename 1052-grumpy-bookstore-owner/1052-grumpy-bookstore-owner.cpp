class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        vector<int> vec;
        int ans=0;
        for(int i=0;i<grumpy.size();i++)
        {
            if(grumpy[i]==0)
            {
                ans+=customers[i];
                vec.push_back(0);
            }
            else
            {
                vec.push_back(customers[i]);
            }
        }
        int left=0;
        int val=0,check=0;
        for(int i=0;i<grumpy.size();i++)
        {
          if(minutes>i)
              val+=vec[i];
           else
           {
               val=val-vec[left];
               left++;
               val+=vec[i];
           }
            cout<<val<<" ";
            check=max(val,check);
        }
        ans=ans+check;
        
        
        return ans;
        
    }
};