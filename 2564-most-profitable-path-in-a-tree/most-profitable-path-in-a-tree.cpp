class Solution {
public:
bool dfsToZero(int node,vector<int> &timeOfVisByBob,vector<vector<int>> &adj)
{
    //if(node==0) return true;

    bool pathLeadsToZero=false;
    for(auto v: adj[node])
    {
        if(timeOfVisByBob[v]==INT_MAX) // v is not visited
        {
            timeOfVisByBob[v]=timeOfVisByBob[node]+1;
            if(v==0) return true;

            pathLeadsToZero=pathLeadsToZero | dfsToZero(v,timeOfVisByBob,adj);
        }
    }

    if(pathLeadsToZero==false)
    timeOfVisByBob[node]=INT_MAX; // this node will not be vis by Bob

    return pathLeadsToZero;
}
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1,maxi=INT_MIN;
        vector<vector<int>> adj(n,vector<int>());
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v); // u -> v
            adj[v].push_back(u); // v -> u
        }
        vector<int> timeOfVisByBob(n,INT_MAX);

        timeOfVisByBob[bob]=0; // start dfs from 'bob' to '0'
        dfsToZero(bob,timeOfVisByBob,adj);

        queue<int> q;
        vector<int> timeOfVisByAlice(n,INT_MAX),pointsTillNode(n,0);
        timeOfVisByAlice[0]=0;
        q.push(0);

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();

            if(timeOfVisByAlice[curNode] < timeOfVisByBob[curNode])
            {
                pointsTillNode[curNode]+=amount[curNode];
            }
            else if(timeOfVisByAlice[curNode] == timeOfVisByBob[curNode])
            {
                pointsTillNode[curNode]+=amount[curNode]/2;
            }

            bool isLeaf=true;

            for(auto neighbour:adj[curNode])
            {
                if(timeOfVisByAlice[neighbour]==INT_MAX) // neighbour not vis till now
                {
                    timeOfVisByAlice[neighbour]=timeOfVisByAlice[curNode]+1;
                    pointsTillNode[neighbour]=pointsTillNode[curNode];
                    q.push(neighbour);
                    isLeaf=false;
                }
            }

            if(isLeaf)
            maxi=max(maxi,pointsTillNode[curNode]);
        }

        return maxi;
    }
};