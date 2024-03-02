class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(char i:s)
        {
            if(i-'0'==1)
                count++;
        }
        int len=s.size();
        string str="";
        for(int i=0;i<len-1;i++)
        {
            if(count>1)
            {
               str+="1";
                count--;
            }
            else
            {
                str+="0";
            }
        }
       str+="1";
            
      return str;  
    }
};