class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> pq;
        vector<int> ans;
        int count=0,prev=0;
        for(int i=0;i<nums.size();i++)
        {   int val=nums[i];
            while(val)
            {
                if(val%2)
                    count++;
                val=val/2;
            }
 
           if(count==prev)
               pq.push(nums[i]);
            else
            {
                while(!pq.empty())
                {
                    ans.push_back(pq.top());
                    pq.pop();
                }
                pq.push(nums[i]);
                prev=count;
            }
         count=0;
        }
        
        while(!pq.empty())
                {
                    ans.push_back(pq.top());
                    pq.pop();
                }
        for(int i=1;i<nums.size();i++)
        {
            if(ans[i-1]>ans[i])
                return false;
        }
        return true;
    }
};