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
                customers[i]=0;
            }
        }
        int left=0;
        int val=0,check=0;
        for(int i=0;i<grumpy.size();i++)
        {
          if(minutes>i)
              val+=customers[i];
           else
           {
               val=val-customers[left];
               left++;
               val+=customers[i];
           }
            check=max(val,check);
        }
        ans=ans+check;
        
        
        return ans;
        
    }
};