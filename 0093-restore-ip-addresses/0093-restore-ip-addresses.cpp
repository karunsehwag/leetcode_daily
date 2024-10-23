class Solution {
public:
    void dp(int in,vector<string>& ans,string str,string str1,string s,int count)
    {
        if(in>=s.size()||count>4)
            return;
        str1+=s[in];
        if(str1.size()<4)
        {
        dp(in+1,ans,str,str1,s,count);
        int val=stoi(str1);
        if(val<=255&&(str1[0] != '0' || str1 == "0"))
        {
           str=str.empty()?str1:str+"."+str1;
           count++;
           str1.erase();
           // cout<<str<< "  "<<count<<"  "<<in<<endl;  
            if(count==4&&in==s.size()-1)
            {
            ans.push_back(str);
             return;
            }
           dp(in+1,ans,str,str1,s,count); 
        }
        
        }
        
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string str="";
        string str1="";
        dp(0,ans,str,str1,s,0);
        return ans;
    }
};