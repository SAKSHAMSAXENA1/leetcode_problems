class DisjointSet{
    vector<int> size,parent;
    unordered_map<int,int> compAndValue;
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
        return parent[node]=findUPar(parent[node]);
    }

    void unionBySize(int u,int v,int wt)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);

        if(compAndValue.find(ulp_u)==compAndValue.end())
        compAndValue[ulp_u]=INT_MAX;

        if(compAndValue.find(ulp_v)==compAndValue.end())
        compAndValue[ulp_v]=INT_MAX;

        if(ulp_u==ulp_v) // both u & v belong to the same component
        {
            compAndValue[ulp_u]&=wt;
            return; 
        } 

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
            compAndValue[ulp_v]&=compAndValue[ulp_u] & wt;
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
            compAndValue[ulp_u]&=compAndValue[ulp_v] & wt;
        }
    }

    int andVal(int u)
    {
        return compAndValue[u];
    }
};
class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        vector<int> res;
        for(auto it:edges)
        {
            int u=it[0],v=it[1],wt=it[2]; // it=[u,v,wt]
            ds.unionBySize(u,v,wt);
        }

        for(auto it:query)
        {
            int u=it[0],v=it[1];
            int ulp_u=ds.findUPar(u),ulp_v=ds.findUPar(v);
            if(u==v)
                res.push_back(0); 
            else if(ulp_u!=ulp_v)
                res.push_back(-1);
            else
                res.push_back(ds.andVal(ulp_u));
        }

        return res;
    }
};