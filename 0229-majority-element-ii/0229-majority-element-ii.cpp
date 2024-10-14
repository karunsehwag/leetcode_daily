class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int cand1=INT_MIN,cand2=INT_MIN;
        for(int x:nums)
        {
            if(count1==0&&x!=cand2)
            {
                cand1=x;
                count1=1;
            }
            else if(count2==0&&x!=cand1)
            {    
                cand2=x;
                count2=1;
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
        vector<int> vec;
        count1=0,count2=0;
        for(int x:nums)
        {
            if(cand1==x)
                count1++;
            if(cand2==x)
                count2++;
        }
        if(count1>floor(nums.size()/3))
            vec.push_back(cand1);
        if(count2>floor(nums.size()/3))
            vec.push_back(cand2);
        return vec;
        
    }
};