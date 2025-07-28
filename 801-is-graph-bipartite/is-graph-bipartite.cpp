class Solution {
public:
bool isComponentBipartite(int node,vector<vector<int>> &graphs,vector<int> &color)
{
    for(auto neighbour:graphs[node])
    {
        if(color[neighbour]==-1) // neighbour is not yet colored
        {
            color[neighbour]=!color[node];
            if(isComponentBipartite(neighbour,graphs,color)==false)
            return false;
        }
        else if(color[neighbour]==color[node]) return false;
    }

    // no false was returned
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1); // initially all node uncolored

        for(int node=0;node<n;node++)
        {
            if(color[node]==-1) // node not colored yet
            {
                color[node]=0;
                if(isComponentBipartite(node,graph,color)==false)
                return false;
            }
        }

        // all components are bipartite
        return true;
    }
};