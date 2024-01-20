class Solution {
public:
    const int mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr)
    {
        int n=arr.size();
        vector<int> vec(n,-1);
        vector<int> vec1(n,n);
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&(arr[st.top()]>=arr[i]))
                st.pop();
            if(!st.empty())
               vec[i]=st.top();
            st.push(i);     
        }
        st=stack<int>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty()&&(arr[st.top()]>arr[i]))
                st.pop();
             if(!st.empty())
                vec1[i]=st.top();
            st.push(i);       
        }
        long long int  ans=0;
        for(int i=0;i<n;i++)
        {
       ans = (ans + (static_cast<long long int>(i - vec[i]) * (vec1[i] - i) * arr[i])) % mod;
            ans%=mod;
        }
        return ans;
    }
};