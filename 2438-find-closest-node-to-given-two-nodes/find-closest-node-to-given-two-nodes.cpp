class Solution {
public:
void dfs(int node,vector<int> &edges,vector<int> &dist)
{
    int adjNode=edges[node];

    if(adjNode!=-1 && dist[node]+1<dist[adjNode])
    {
        dist[adjNode]=dist[node]+1;
        dfs(adjNode,edges,dist);
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),minDist=INT_MAX,minDistNode=-1;
        vector<int> distFromNode1(n,INT_MAX),distFromNode2(n,INT_MAX);

        distFromNode1[node1]=0;
        distFromNode2[node2]=0;

        dfs(node1,edges,distFromNode1);
        dfs(node2,edges,distFromNode2);

        for(int i=0;i<n;i++)
        {
            int distOfCurNode=max(distFromNode1[i],distFromNode2[i]);

            if(distOfCurNode < minDist)
            {
                minDist=distOfCurNode;
                minDistNode=i;
            }
        }

        return minDistNode;
    }
};