class Solution {
public:
    class Disjointset
    {
        vector<int> parent,size;
        public:
        Disjointset(int n)
        {
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
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
            if(u_v==u_u)
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
        {return size[n];}
    };
    int largestIsland(vector<vector<int>>& grid) {
        
        vector<vector<int>> adj;
        vector<int> relative={-1,0,1,0,-1};
        int n=grid.size();
        Disjointset ds(n*n);
        for(int row=0;row<grid.size();row++)
        {
            for(int col=0;col<grid[0].size();col++)
            {
                if(grid[row][col]==1)
                {
                    for(int i=0;i<4;i++)
                    {
                        int newr=row+relative[i];
                        int newc=col+relative[i+1];
                        if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1)
                        {
                            int node=row*n+col;
                            int adjnode=newr*n+newc;
                            ds.unionsize(node,adjnode);
                        }
                    }
                }
            }
        }
        
        
        int mx=0;
         for(int row=0;row<grid.size();row++)
        {
            for(int col=0;col<grid[0].size();col++)
            {   if(grid[row][col]==1)
                   continue;
             
                 set<int> component;
                    for(int i=0;i<4;i++)
                    {
                        int newr=row+relative[i];
                        int newc=col+relative[i+1];
                        if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1)
                        {
                            component.insert(ds.findupar(newr*n+newc));
                        }
                    }
             int sizetotal=0;
             for(auto it:component)
             {
                 sizetotal+=ds.getsize(it);
             }
             mx=max(sizetotal+1,mx);
             
                
            }
        }
        
        for(int i=0;i<n*n;i++)
        {
            mx=max(mx,ds.getsize(ds.findupar(i)));
        }  
        
        return mx;
        
    
        
        
    }
};