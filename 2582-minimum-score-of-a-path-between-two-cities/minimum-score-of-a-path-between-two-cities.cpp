
class DisjointSet{
    public:
    vector<int> parent,minDist;

    DisjointSet(int &n)
    {
        parent.resize(n+1);
        minDist.resize(n+1,INT_MAX);

        for(int i=0;i<=n;i++)
        parent[i]=i;
    }

    int findUPar(int node)
    {
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int &u,int &v,int &dist)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);

        if(ulp_u==ulp_v) 
        {
            minDist[ulp_u]=min(minDist[ulp_u],dist);
            return;
        }

        parent[ulp_v]=ulp_u;
        minDist[ulp_u]=min({minDist[ulp_u],minDist[ulp_v],dist});
    }
};
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);

        for(auto it:roads)
        {
            int u=it[0],v=it[1],dist=it[2];
            ds.unionBySize(u,v,dist);
        }

        return ds.minDist[ds.findUPar(1)];
    }
};