class DisjointSet{
    vector<int> size,parent,rank;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++) 
        parent[i]=i;
    }

    int findUPar(int node)
    {
        if(node==parent[node]) return node;
        //else
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
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

    void unionByRank(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(rank[ulp_u]<rank[ulp_v])
        {
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u])
        {
            parent[ulp_v]=ulp_u;
        }
        else // rank[ulp_u]==rank[ulp_v]
        {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size(),cntUltimateParents=0;
        DisjointSet ds(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    ds.unionByRank(i,j);
                }
            }
        }
        // each component has a unique ultimate parent
        // so no of unique ultimate parents=no of components
        // for an ultimate parent, node=parent[node]

        for(int i=0;i<n;i++)
        {
            if(i==ds.findUPar(i)) cntUltimateParents++;
        }

        return cntUltimateParents;
    }
};