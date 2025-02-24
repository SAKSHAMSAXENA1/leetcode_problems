class DisjointSet{
    public:
    unordered_map<int,int> size,parent;
    
    DisjointSet(vector<vector<int>> &stones)
    {
        for(auto it:stones)
        {
            int x=it[0],y=it[1];
            int node=x*(1e4+1)+y;
            size[node]=1;
            parent[node]=node;
        }
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
        if(ulp_u==ulp_v) return; //aready part of the same component
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
        return size[node];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
       int n=stones.size(),maxi=0;
       DisjointSet ds(stones);
       for(int i=0;i<n;i++)
       {
        int x=stones[i][0],y=stones[i][1];
        int curNode=x*(1e4+1)+y;
        for(int j=i+1;j<n;j++)
        {
            int nx=stones[j][0],ny=stones[j][1];
            if(nx==x || ny==y)
            {
                int adjNode=nx*(1e4+1)+ny;
                ds.unionBySize(curNode,adjNode);
            }
        }
        //maxi=max(maxi,ds.getSize(ds.findUPar(curNode)));
       }
       /*if(maxi>1) return maxi-1;
       else return 0;*/
       int cnt=0;
       for(auto it:ds.parent)
       {
        int node=it.first,ulp_node=ds.findUPar(node);
        if(node==ulp_node)
        {
            //if(ds.getSize(ulp_node)>1)
            cnt+=ds.getSize(ulp_node)-1;
        }
       }
       return cnt;
    }
};