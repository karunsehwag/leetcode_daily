class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        Disjoint u(20002);
        int n=stones.size();
        for(int i=0;i<n;i++)
        {
            u.unionfind(stones[i][0],stones[i][1]+10001);
        }
        int count=0;
        for(int i=0;i<20002;i++)
        {
            if(u.findupar(i)==i&&u.getsize(i)>1)
                count++;
        }
        
        return n-count;
        
    }
    
    class Disjoint{
        
        vector<int> parent,size;
        public:
        Disjoint(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        
        int findupar(int n)
        {
            if(parent[n]==n)
                return n;
            
            return parent[n]=findupar(parent[n]);
        }
        
        void unionfind(int u,int v)
        {
            int u_u=findupar(u);
            int u_v=findupar(v);
            if(u_u==u_v)
                return;
            if(size[u_u]>size[u_v])
            {
                parent[u_v]=u_u;
                size[u_u]+=size[u_v];
            }
            else
            {
                parent[u_u]=u_v;
                size[u_v]+=size[u_u];
            }
        }
        
        int getsize(int n)
        {return size[findupar(parent[n])];}
    };
};