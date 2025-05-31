class Solution {
public:
void bfs(int &node,vector<int> &edges,vector<int> &dist)
{
    queue<int> q;
    vector<bool> vis(edges.size(),false);
    q.push(node);
    vis[node]=true;

    while(!q.empty())
    {
        int curNode=q.front();
        q.pop();

        int adjNode=edges[curNode];

        if(adjNode!=-1 && !vis[adjNode])
        {
            vis[adjNode]=true;
            dist[adjNode]=dist[curNode]+1;
            q.push(adjNode);
        }
    }
}
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size(),minDist=INT_MAX,minDistNode=-1;
        vector<int> distFromNode1(n,INT_MAX),distFromNode2(n,INT_MAX);

        distFromNode1[node1]=0;
        distFromNode2[node2]=0;

        bfs(node1,edges,distFromNode1);
        bfs(node2,edges,distFromNode2);

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