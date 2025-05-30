class Solution {
public:
    pair<int,int> f(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> distFromNode1(n,INT_MAX);
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(node1);
        vis[node1]=true;
        distFromNode1[node1]=0; // node1->node1 dist is 0;

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();

            int adjNode=edges[curNode];

            if(adjNode!=-1 && distFromNode1[curNode]+1<distFromNode1[adjNode])
            {
                distFromNode1[adjNode]=distFromNode1[curNode]+1;
                q.push(adjNode);
                vis[adjNode]=true;
            }
        }
        
        if(vis[node2]) //return distFromNode1[node2];
        return {distFromNode1[node2],node2};

        q.push(node2);
        int distFromNode2=0;
        vis[node2]=true;

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();

            int adjNode=edges[curNode];

            if(adjNode!=-1)
            {
                if(vis[adjNode]) 
                return {max(distFromNode1[adjNode],distFromNode2+1),adjNode};
                else
                {
                    q.push(adjNode);
                    vis[adjNode]=true;
                    distFromNode2++;
                }
            }

        }

        return {INT_MAX,-1};
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        auto [dist1,commonNode1]=f(edges,node1,node2);
        auto [dist2,commonNode2]=f(edges,node2,node1);

        if(dist1<dist2) return commonNode1;
        else if(dist2<dist1) return commonNode2;

        // else dist1==dist2
        if(dist1==INT_MAX) return -1;

        return min(commonNode1,commonNode2);
    }
};