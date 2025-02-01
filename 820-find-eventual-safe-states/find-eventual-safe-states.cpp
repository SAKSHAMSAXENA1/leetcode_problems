class Solution {
public:
bool dfsCheck(int node,vector<vector<int>> &graph,vector<bool> &vis,
vector<bool> &visOnSamePath)
{
    vis[node]=1;
    visOnSamePath[node]=1;
    //check[node]=0; // let us assume this node is not a safe node

    for(auto neighbour: graph[node])
    {
        if(!vis[neighbour])
        {
            if(dfsCheck(neighbour,graph,vis,visOnSamePath)==true) 
            return true; // this dfs call detects a cycle further down the recursion tree
        }
        else if(visOnSamePath[neighbour]) return true; // cycle is detected
    }

    // cycle is not detected
    //check[node]=1;
    visOnSamePath[node]=0;
    return false;
}
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,0),visOnSamePath(n,0),check(n,0);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfsCheck(i,graph,vis,visOnSamePath);
            }
        }

        vector<int> safeNodes;
        for(int i=0;i<n;i++)
        {
            if(!visOnSamePath[i]) safeNodes.push_back(i);
        }

        return safeNodes;
    }
};