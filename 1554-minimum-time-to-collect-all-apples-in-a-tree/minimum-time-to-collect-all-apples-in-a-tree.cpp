class Solution {
public:
bool dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &leadsToApples,
vector<bool> &hasApple)
{
    vis[node]=true;

    leadsToApples[node]=hasApple[node];

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        leadsToApples[node]=leadsToApples[node]|dfs(neighbour,adj,vis,leadsToApples,hasApple);
    }

    return leadsToApples[node];
}

void dfsTime(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<bool> &leadsToApples,
int &timer)
{
    vis[node]=true;

    if(leadsToApples[node]==false)
    {
        if(node!=0)
        timer--;

        return;
    }

    for(auto neighbour: adj[node])
    {
        if(!vis[neighbour])
        {
            timer++;
            dfsTime(neighbour,adj,vis,leadsToApples,timer);
        }
    }

    if(node!=0) 
    timer++; // time increases to traverse back the edge to parent
}
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<bool> leadsToApples(n,false),vis(n,false);
        vector<vector<int>> adj(n,vector<int>());

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0,adj,vis,leadsToApples,hasApple);

        int timer=0;
        for(int i=0;i<n;i++) vis[i]=false; // reset vis to false
        dfsTime(0,adj,vis,leadsToApples,timer);
        return timer;
    }
};