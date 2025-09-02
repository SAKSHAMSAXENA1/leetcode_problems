class Solution {
public:
void dfs(int node,int parent,int curTime,vector<int> &adj,vector<bool> &vis,
vector<bool> &pathVis,vector<int> &time,int &res)
{
    vis[node]=true;
    pathVis[node]=true;
    time[node]=curTime;

    int neighbour=adj[node];

    if(neighbour!=-1)
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,node,curTime+1,adj,vis,pathVis,time,res);
        }
        else if(pathVis[neighbour])
        res=max(res,abs(curTime-time[neighbour])+1);
    }

    pathVis[node]=false;
}
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<bool> vis(n,false),pathVis(n,false);
        vector<int> time(n,n+1);
        int res=0;
        vector<int> adj(n);

        for(int i=0;i<n;i++)
        {
            adj[i]=edges[i];
        }

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,-1,0,adj,vis,pathVis,time,res);
            }
        }

        if(res==0) return -1;
        return res;
    }
};