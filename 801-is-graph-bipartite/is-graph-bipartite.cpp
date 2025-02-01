class Solution {
public:
bool bfs(int node,vector<vector<int>> &graph,vector<int> &color)
{
    queue<int> q;
    q.push(node);
    color[node]=0;

    while(!q.empty())
    {
        int curNode=q.front();
        int curCol=color[curNode];
        q.pop();

        for(auto neighbour: graph[curNode])
        {
            if(color[neighbour]==-1)
            {
                color[neighbour]=!color[curNode];
                q.push(neighbour);
            }
            else if(color[neighbour]==color[curNode]) return false;
        }
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
                if(bfs(i,graph,color)==false) return false;
            }
        }

        return true;
    }
};