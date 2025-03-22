class Solution {
public:
void bfs(int &node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &component,
int &componentIndex)
{
    vis[node]=true;
    component[node]=componentIndex;
    queue<int> q;
    q.push(node);
    
    while(!q.empty())
    {
        int curNode=q.front();
        q.pop();

        for(auto neighbour:adj[curNode])
        {
            if(!vis[neighbour])
            {
                vis[neighbour]=true;
                q.push(neighbour);
                component[neighbour]=componentIndex;
            }
        }
    }
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> component(n,0),componentSize(n,0);
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
                bfs(i,adj,vis,component,componentIndex);
                componentIndex++;
            }
    
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