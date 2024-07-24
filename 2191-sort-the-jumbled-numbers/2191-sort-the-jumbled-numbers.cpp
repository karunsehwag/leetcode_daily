class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        vector<vector<int>> vec(nums.size(),vector<int>(2,0));
        for(int i=0;i<nums.size();i++)
        {  int val=nums[i];
            if(val==0)
                vec[i][0]=mapping[val];
         else
         { 
            stack<int> st;      
            while(val>0)
            {   
                st.push(val%10);
                val=val/10;
            }
           val=0;
            while(!st.empty())
            {
                val=mapping[st.top()%10]+val*10;
                st.pop();
            }
            vec[i][0]=val;
             
         }
            vec[i][1]=i;
        }
        vector<int> ans;
        sort(vec.begin(),vec.end());
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(nums[vec[i][1]]);
        }
        return ans;
        
    }
};