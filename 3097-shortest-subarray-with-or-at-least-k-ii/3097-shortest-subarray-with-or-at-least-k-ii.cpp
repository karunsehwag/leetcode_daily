class Solution {
public:
    void contribute(vector<int>& bitvector,int val,bool flag)
    {
        int i=0;
        while(val>0)
        {
            bitvector[i]=bitvector[i]+(flag?1:-1)*val%2;
            val=val/2;
            i++;
        }
    }

    bool validate(vector<int> &bitvector,int k)
    {
        int bitval = 0;
        for(int i=0;i<32;i++)
        {
            
            bitval += (bitvector[i] ? 1 : 0) * pow(2,i); 
        }
        return bitval>=k;
    }
    
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans=INT_MAX,i=0,j=0,n=nums.size();
        vector<int> bitvector(32,0);
        while(j<n)
        {
            contribute(bitvector,nums[j],true);
            while(validate(bitvector,k) and i<=j)
            {
                ans=min(ans,j-i+1);
                contribute(bitvector,nums[i],false);
                i++;
            }
            j++;
        }
       return ans==INT_MAX?-1:ans; 
    }
};