class Solution {
public:
    int getLucky(string s, int k) {
        int ans=0;
        for(char x:s)
        {   int val=0;
            val+=x-'a'+1;
            ans+=val%10;
            ans+=val/10;
        }
        while(k>1)
        {
            int val=0;
            while(ans)
            {
                val+=ans%10;
                ans=ans/10;
            }
            ans=val;
            k--;
        }
        return ans;
    }
};