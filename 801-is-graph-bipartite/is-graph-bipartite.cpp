class Solution {
public:
bool isComponentBipartite(int start,vector<vector<int>> &graphs,vector<int> &color)
{
    queue<int> q;
    q.push(start);
    color[start]=0;

    while(!q.empty())
    {
        int curNode=q.front();
        q.pop();

        for(auto neighbour:graphs[curNode])
        {
            if(color[neighbour]==-1) // neighbour is not yet colored
            {
                color[neighbour]=!color[curNode];
                q.push(neighbour);
            }
            else if(color[neighbour]==color[curNode]) 
            return false;
        }
    }

    // no false was returned
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1); // initially all nodes uncolored

        for(int node=0;node<n;node++)
        {
            if(color[node]==-1) // node not colored yet
            {
                if(isComponentBipartite(node,graph,color)==false)
                return false;
            }
        }

        // all components are bipartite
        return true;
    }
};