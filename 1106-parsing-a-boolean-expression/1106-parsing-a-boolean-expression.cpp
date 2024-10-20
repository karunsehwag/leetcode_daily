class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st1,st2;
        for(char ch:expression)
        {
            if(ch=='!'||ch=='&'||ch=='|')
                st1.push(ch);
            else if(ch=='('||ch=='t'||ch=='f')
            {
                st2.push(ch);
            }
            else if(ch==')')
            {   bool ans;
                bool flag=true;
                if(st1.top()=='&')
                    ans=true;
                else 
                    ans=false;
                while(st2.top()!='(')
                {   bool val=false;
                    if(st2.top()=='f')
                        val=false;
                    else 
                        val=true;
                    if(flag)
                    {
                        ans=val;
                       
                        flag=false;
                    }
                    else
                    {
                        if(st1.top()=='&')
                        {
                           ans=ans&val; 
                        }
                        else if(st1.top()=='|')
                        {
                          ans=ans|val;  
                        }
                        // else if(st1.top()=='!')
                        // {
                        //   ans=!ans;
                        // }
                    }
                 
                  st2.pop();
                  if (st1.top() == '!') {
                    ans = !ans; 
                }
                
                    
                }
                 st2.pop();
                 //cout<<ans<<endl;
                 ans?st2.push('t'):st2.push('f');
                 st1.pop();
            }
        }
        return st2.top()=='f'?false:true;
        
    }
};