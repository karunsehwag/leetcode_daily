class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> vec1,vec2;
        int count=0;
        for(int x:nums)
        {
            if(pivot<x)
                vec1.push_back(x);
            else if(pivot>x)
                vec2.push_back(x);
            else
                count++;      
        }
        int r=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(vec2.size()>i)
                nums[i]=vec2[i];
            else if(count>0)
            {
                count--;
                nums[i]=pivot;
            }
            else
            {   if(r==-1)
                  r=i;
                nums[i]=vec1[i-r];
            }
        }
        
        
       return nums; 
    }
};