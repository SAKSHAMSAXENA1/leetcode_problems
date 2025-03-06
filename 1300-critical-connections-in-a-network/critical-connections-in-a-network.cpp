class Solution {
    int timer=0;
public:
void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &disc,vector<int> &low,
         vector<bool> &vis,vector<vector<int>> &res)
    {
        vis[node]=true;
        disc[node]=low[node]=timer;
        timer++;

        for(auto neighbour:adj[node])
        {
            if(neighbour==parent) continue;

            if(!vis[neighbour]) // unvisited neighbour means it is a child
            {
                dfs(neighbour,node,adj,disc,low,vis,res);
                low[node]=min(low[node],low[neighbour]);

                if(low[neighbour]>disc[node])
                {
                    res.push_back({node,neighbour});
                }
            }
            else // visited neighbour which is not parent means it is ancestor, BACK EDGE
            {
                low[node]=min(low[node],disc[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> disc(n,-1),low(n,-1);
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n,vector<int>()),res;

        for(auto it:connections)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,adj,disc,low,vis,res);
            }
        }

        return res;
    }
};