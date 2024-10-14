class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int cand1=0,cand2=0;
        for(int x:nums)
        {
            if(count1==0&&x!=cand2)
            {
              count1++;
              cand1=x;
            } 
            else if(count2==0&&x!=cand1)
            {
              count2++;
              cand2=x;
            }
            else if(cand1==x)
            count1++;
            else if(cand2==x)
             count2++;
             else
             {
               count1--;
               count2--;
             }

        }
        count1=0,count2=0;
        for(int x:nums)
        {
          if(x==cand1)
            count1++;
            else if(x==cand2)
               count2++;
        }
        vector<int> vec;
        int threshold=nums.size()/3;
        if(count1>threshold)
           vec.push_back(cand1);
        if(count2>threshold)
           vec.push_back(cand2);   
      return vec;  
    }
};