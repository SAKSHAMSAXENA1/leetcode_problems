class Solution {
public:
void dfs(int &node,vector<vector<int>> &adj,vector<bool> &vis,int &nodesCnt,int &totOutdegree)
{
    vis[node]=true;
    totOutdegree+=adj[node].size();
    nodesCnt++;

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,adj,vis,nodesCnt,totOutdegree);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n,vector<int>());
        int cnt=0;
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int nodesCnt=0,totOutdegree=0;
                dfs(i,adj,vis,nodesCnt,totOutdegree);
                if(totOutdegree==nodesCnt*(nodesCnt-1)) cnt++;
            }
        }

        return cnt;
    }
};