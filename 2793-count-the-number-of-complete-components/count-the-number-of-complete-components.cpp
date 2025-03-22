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

        if(ulp_u==ulp_v) // both u and v belong to the same component
        return;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else // size[ulp_v]<=size[ulp_u]
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }

    int getSize(int u)
    {
        return size[u];
    }
};
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        unordered_set<int> incompleteComponents;
        vector<int> neighbours(n,0);
        int components=0;
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            ds.unionBySize(u,v);
            neighbours[u]++;
            neighbours[v]++;
        }

        for(int i=0;i<n;i++)
        {
            if(neighbours[i]!=ds.getSize(ds.findUPar(i))-1)
            incompleteComponents.insert(ds.findUPar(i)); 

            if(i==ds.findUPar(i)) components++;
        }

        return components-incompleteComponents.size();
    }
};