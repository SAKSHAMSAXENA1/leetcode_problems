class Solution {
public:
void dfs(int &node,vector<vector<int>> &adj,vector<bool> &vis,unordered_map<int,int> &component,
int &componentIndex)
{
    vis[node]=true;
    component[node]=componentIndex;

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,adj,vis,component,componentIndex);
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> component,componentSize;
        vector<vector<int>> adj(n,vector<int>());
        vector<bool> vis(n,false);
        unordered_set<int> incompleteComponents;
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int componentIndex=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,component,componentIndex);
                componentSize[componentIndex]=1;
                componentIndex++;
            }
            else
            componentSize[component[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(adj[i].size()!=componentSize[component[i]]-1)
            incompleteComponents.insert(component[i]);
        }
        
        return componentIndex-incompleteComponents.size();
    }
};