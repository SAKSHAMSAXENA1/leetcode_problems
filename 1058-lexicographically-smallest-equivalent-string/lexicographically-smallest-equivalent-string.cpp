class DisjointSet{
    int parent[26]={0};
public:
    DisjointSet()
    {
        for(int i=0;i<26;i++)
        parent[i]=i; // each char is a parent of itself
    }

    int findUPar(int node)
    {
        if(node==parent[node]) return node;
        else return parent[node]=findUPar(parent[node]);
    }

    void unionByLexicographicalOrder(int u,int v)
    {
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);

        if(ulp_u == ulp_v) // both u & v already part of the same component
        return;

        if(ulp_u < ulp_v)
        {
            parent[ulp_v]=ulp_u;
        }
        else // ulp_v < ulp_u
        {
            parent[ulp_u]=ulp_v;
        }
    }
};
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds;
        int n=s1.size();
        string res="";

        for(int i=0;i<n;i++)
        {
            ds.unionByLexicographicalOrder(s1[i]-'a',s2[i]-'a');
        }

        for(auto it:baseStr)
        {
            res.push_back(ds.findUPar(it-'a')+'a');
        }

        return res;
    }
};