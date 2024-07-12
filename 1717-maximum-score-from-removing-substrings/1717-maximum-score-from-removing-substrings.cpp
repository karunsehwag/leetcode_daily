class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st,st2;
        
        int ans=0;
        for(char ch:s)
        {   if(x>y)
           {if(!st.empty()&&ch=='b'&&st.top()=='a')
           {st.pop();
           ans+=x;}
            else
                st.push(ch);
           }
         else
         {
             if(!st.empty()&&ch=='a'&&st.top()=='b')
             {st.pop();
             ans+=y;}
             else
                 st.push(ch);
             
             
         }
        }
        while(!st.empty())
        {
            if(st2.empty())
            {
               st2.push(st.top());
               st.pop();   
            }
            else
            {
               if(st.top()=='a'&&st2.top()=='b')
               {ans+=x;
               st.pop();
               st2.pop();}
                else if(st.top()=='b'&&st2.top()=='a')
                {ans+=y;
                 st.pop();
                 st2.pop();
                }
                else
                {st2.push(st.top());
                st.pop();}
            }
            
        }
        
        return ans;
        
        
    }
};