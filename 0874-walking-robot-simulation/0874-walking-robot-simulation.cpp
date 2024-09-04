class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int,int>> st;
        for(auto it:obstacles)
        {   
                 st.insert({it[0],it[1]});
        }
        int x=0,y=0;
        int dir=90;
        int ans=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]==-1)
                dir=(dir-90+360)%360;
            else if(commands[i]==-2)
            {dir=(dir+90+360)%360;}
            else
            {
             if(dir==0)
             {
             for(int k=0;k<commands[i];k++)
             {
                 if(st.count({x+1,y})>0)
                     break;
                 x++;
             }
              
              
              }
            else if(dir==90)
            {
                 for(int k=0;k<commands[i];k++)
             {
                 if(st.count({x,y+1})>0)
                     break;
                 y++;
             }
            
            
            }
            else if(dir==180)
            {
            for(int k=0;k<commands[i];k++)
             {
                 if(st.count({x-1,y})>0)
                     break;
                 x--;
             }
            }
            else if(dir==270)
            {
                for(int k=0;k<commands[i];k++)
             {
                 if(st.count({x,y-1})>0)
                     break;
                 y--;
             }
            }
            }
            int g=pow(x,2)+pow(y,2);
            ans=max(ans,g);
          //  cout<<x<<"  "<<y<<"  "<<dir<<endl;
        }
        
        return ans;
    }
};