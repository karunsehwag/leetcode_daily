class Solution {
public:
    bool judgeSquareSum(int c) {
        set<int> st;
        for(long long int i=0;i*i<=c;i++)
        {
            st.insert(i*i);
            if(st.find(c-i*i)!=st.end())
                return true;
        }
      return false;  
    }
};