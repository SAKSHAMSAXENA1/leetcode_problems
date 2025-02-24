class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);

        for(int i=0;i<=n;i++) parent[i]=i;
    }

    int findUPar(int node)
    {
        if(node==parent[node]) return node;
        // else
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return; // both u & v belong to the same component

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

    int getSize(int node)
    {
        return size[findUPar(node)];
    }
};
class Solution {
public:
    bool isValid(int &ni,int &nj,int &n)
    {
        return 0<=ni && ni<n && 0<=nj && nj<n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size(),maxi=0;
        DisjointSet ds(n*n);
        int di[]={-1,0,1,0},dj[]={0,-1,0,1};

        // connect all original ones to form islands
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    int curNode=i*n+j;
                    for(int k=0;k<2;k++)
                    {
                        int ni=i+di[k],nj=j+dj[k];

                        if(isValid(ni,nj,n) && grid[ni][nj])
                        {
                            int adjNode=ni*n+nj;
                            ds.unionBySize(curNode,adjNode);
                        }
                    }
                    maxi=max(maxi,ds.getSize(curNode));
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) // can be converted
                {
                    int totAdjSize=0;
                    unordered_set<int> adjNodeParents;
                    for(int k=0;k<4;k++)
                    {
                        int ni=i+di[k],nj=j+dj[k];
                        
                        if(isValid(ni,nj,n) && grid[ni][nj]==1)
                        {
                            int adjNode=ni*n+nj;
                            int adjNodeParent=ds.findUPar(adjNode);
                            if(adjNodeParents.find(adjNodeParent)==adjNodeParents.end())
                            {
                                adjNodeParents.insert(adjNodeParent);
                                totAdjSize+=ds.getSize(adjNode);
                            }
                        }
                    }
                    maxi=max(maxi,totAdjSize+1);
                }
            }
        }
        return maxi;
    }
};