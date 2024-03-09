class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=nums1.size();
        int j=nums2.size();
        int h=0;
        int p=0;
        while(h<i&&p<j)
        {
            if(nums1[h]==nums2[p])
                return nums1[h];
            else if(nums1[h]>nums2[p])
                p++;
            else 
                h++;
        }
      return -1;  
    }
};