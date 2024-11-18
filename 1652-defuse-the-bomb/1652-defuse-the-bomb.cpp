class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        vector<int> ans;
        int n=code.size();
       
        for(int i=0;i<n;i++)
        {   
            int sum=0;
            if(k>=0)
            {    
            for(int j=i+1;j<=(i+k);j++)
                sum+=code[j%n];
            }
            else
            { 
               for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }
            }
            ans.push_back(sum); 
        }
        return ans;
    }
};