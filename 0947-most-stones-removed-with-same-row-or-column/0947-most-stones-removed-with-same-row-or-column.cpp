class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<stones.size();i++)
    {   
       mp[stones[i][0]].push_back(stones[i][1]+10001);
       mp[stones[i][1]+10001].push_back(stones[i][0]);
    } 
 
     stack<int> st;
     vector<int> vis(20002,0);
     int count=0;
     for(int i=0;i<stones.size();i++)
     {
         if(vis[stones[i][0]]==0)
         {   count++;
             st.push(stones[i][0]);
             while(!st.empty())
             {
                int node=st.top();
                st.pop();
                vis[node]=1;
                for(int it:mp[node])
                {   
                    if(vis[it]==0)
                     {   
                        st.push(it);   
                    }
                }
                 
             }   
             
         }
     }
        
        return stones.size()-count;
        
    }
};