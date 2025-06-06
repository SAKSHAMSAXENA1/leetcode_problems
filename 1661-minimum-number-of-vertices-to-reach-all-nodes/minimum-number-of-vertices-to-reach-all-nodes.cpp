class Solution {
public:
void dfs(int node,vector<bool> &vis,vector<vector<int>> &adj)
{
    vis[node]=true;

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        dfs(neighbour,vis,adj);
    }
}
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>());
        vector<int> indegree(n,0),res,topoSort;
        vector<bool> vis(n,false);
        queue<int> q;
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            topoSort.push_back(node);

            for(auto neighbour:adj[node])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0)
                q.push(neighbour);
            }
        }

        for(auto it:topoSort)
        {
            if(!vis[it])
            {
                dfs(it,vis,adj);
                res.push_back(it);
            }
        }

        return res;
    }
};