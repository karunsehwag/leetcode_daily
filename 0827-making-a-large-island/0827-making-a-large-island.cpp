class Disjointset
{
    vector<int> size,parent;
    public:
    Disjointset(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findpar(int node)
    {
        if(node==parent[node])
            return node;
        return parent[node]=findpar(parent[node]);
    }
    
void unionsize(int u ,int v)
{
    int u_u=findpar(u);
    int v_v=findpar(v);
    
    if(u_u==v_v)
    {
        return;
    }
    else if(size[u_u]>size[v_v])
    {
        parent[v_v]=u_u;
        size[u_u]+=size[v_v];
    }
    else 
    {
        parent[u_u]=v_v;
        size[v_v]+=size[u_u];
    }
}
    
    int getsize(int n)
    {
        return size[findpar(n)];
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        Disjointset ds(n*n);
        vector<int> vec={-1,0,1,0,-1};
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {  if(grid[i][j]==1)
            {
                for(int k=0;k<vec.size()-1;k++)
                {
                    int newr=i+vec[k];
                    int newc=j+vec[k+1];
                    if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1)
                    {
                        ds.unionsize(newr*n+newc,i*n+j);
                    }
                }
            }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                    continue;
                set<int> component;
                 for(int k=0;k<vec.size()-1;k++)
                {
                    int newr=i+vec[k];
                    int newc=j+vec[k+1];
                    if(newr>=0&&newr<n&&newc>=0&&newc<n&&grid[newr][newc]==1)
                    {
                        component.insert(ds.findpar(newr*n+newc));
                    }
                }
                int sizetotal=0;
                for(int it:component)
                {
                    sizetotal+=ds.getsize(ds.findpar(it));
                }
                
                ans=max(ans,sizetotal+1);
                
                
            }
        }
        
         for(int i=0;i<n*n;i++)
        {
            ans=max(ans,ds.getsize(ds.findpar(i)));
        }  
        
        
        return ans;
        
    }
};