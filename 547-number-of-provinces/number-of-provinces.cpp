class Solution {
public:
void dfs(int node, vector<vector<int>> &adj,vector<bool> &vis,int &n)
{
    vis[node]=true;

    for(int i=0;i<n;i++)
    {
        if(i==node) continue;

        if(adj[node][i]==1 && !vis[i]) dfs(i,adj,vis,n);
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int res=0,n=isConnected.size();
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis,n);
                res++;
            }
        }

        return res;
    }
};