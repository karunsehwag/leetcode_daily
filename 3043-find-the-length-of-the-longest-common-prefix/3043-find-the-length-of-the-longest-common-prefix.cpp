class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
        for(int x: arr1)
        {
            while(x)
            {
                st.insert(x);
                x=x/10;
            }
            
        }
        int ans=0;
        for(int x: arr2)
        {  int count=0;
            while(st.find(x)==st.end() and x>0)
            {
                x=x/10;
            }
            if(x>0)
            {
                ans=max(ans,static_cast<int>(log10(x))+1);
            }    
        }
        return ans;
        
    }
};