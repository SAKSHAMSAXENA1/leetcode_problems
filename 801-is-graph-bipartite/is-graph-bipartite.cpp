class Solution {
public:
bool dfs(int node,vector<vector<int>> &graph, vector<int> &color)
{
    for(auto neighbour:graph[node])
    {
        if(color[neighbour]==-1)
        {
            color[neighbour]=!color[node];
            if(dfs(neighbour,graph,color)==false) return false;
        }
        else if(color[neighbour]==color[node]) return false;
    }

    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                color[i]=0;
                if(dfs(i,graph,color)==false) return false;
            }
        }

        return true;
    }
};