class Solution {
public:
    char findKthBit(int n, int k) {
        string str="0";
        for(int i=1;i<n;i++)
        {
            string str1=str;
            str=str+"1";
            for(int j=0;j<str1.size();j++)
            {
                if(str1[j]=='1')
                    str1[j]='0';
                else
                    str1[j]='1';
            }
            reverse(str1.begin(),str1.end());
            str+=str1;
        }
       
        return str[k-1];
        
    }
};