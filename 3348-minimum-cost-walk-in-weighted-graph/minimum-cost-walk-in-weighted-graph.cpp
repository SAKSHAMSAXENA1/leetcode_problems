class Solution {
public:
void dfs(int &node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &comp,int &componentNo)
{
    vis[node]=true;
    comp[node]=componentNo;

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,adj,vis,comp,componentNo);
        }
    }
}
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<bool> vis(n,false);
        vector<int> comp(n),res;
        unordered_map<int,int> compAndValue;
        vector<vector<int>> adj(n);
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int componentNo=1;

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,comp,componentNo);
                compAndValue[componentNo]=INT_MAX;
                componentNo++;
            }
        }

        for(auto it:edges)
        {
            compAndValue[comp[it[0]]]&=it[2]; // it=[u,v,wt] 
        }

        for(auto it:query)
        {
            int u=it[0],v=it[1];
            if(u==v)
                res.push_back(0); 
            else if(comp[u]!=comp[v])
                res.push_back(-1);
            else
                res.push_back(compAndValue[comp[u]]);
        }

        return res;
    }
};