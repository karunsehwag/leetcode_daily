class Solution {
public:
    class Disjointset{
        
        vector<int> parent,size;
        public:
        Disjointset(int n)
        {
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<n;i++)
                parent[i]=i;
        }
        
        int findupar(int node)
        {
            if(node==parent[node])
                return node;
            return parent[node]=findupar(parent[node]);
                
        }
        void unionsize(int u,int v)
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
    };
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        Disjointset Ds(n);
        int counte=0;
        for(vector<int> it:connections)
        {   if(Ds.findupar(it[0])!=Ds.findupar(it[1]))
                Ds.unionsize(it[0],it[1]);
            else
                counte++;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(i==Ds.findupar(i))
            {
                count++;
            }
        }
        if(counte>=count-1)
            return count-1;
        
        return -1;   
    }
};