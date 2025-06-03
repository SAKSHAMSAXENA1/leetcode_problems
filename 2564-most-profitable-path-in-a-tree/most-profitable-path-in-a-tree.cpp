class Solution {
public:
bool dfsToZero(int node,vector<int> &timeOfVisByBob,vector<vector<int>> &adj)
{
    if(node==0) return true;

    bool pathLeadsToZero=false;
    for(auto neighbour: adj[node])
    {
        if(timeOfVisByBob[neighbour]==INT_MAX) // neighbour not visited by Bob till now
        {
            timeOfVisByBob[neighbour]=timeOfVisByBob[node]+1;

            pathLeadsToZero=pathLeadsToZero | dfsToZero(neighbour,timeOfVisByBob,adj);
        }
    }

    if(pathLeadsToZero==false)
    timeOfVisByBob[node]=INT_MAX; // this node will not be vis by Bob

    return pathLeadsToZero;
}

void dfs(int node,int pointsTillCurNode,vector<int> &amount,vector<int> &timeOfVisByAlice,
vector<int> &timeOfVisByBob,vector<vector<int>> &adj,int &maxi)
{
    if(timeOfVisByAlice[node] < timeOfVisByBob[node])
    {
        pointsTillCurNode+=amount[node];
    }
    else if(timeOfVisByAlice[node] == timeOfVisByBob[node])
    {
        pointsTillCurNode+=amount[node]/2;
    }

    bool isLeaf=true;

    for(auto neighbour:adj[node])
    {
        if(timeOfVisByAlice[neighbour]==INT_MAX) // neighbour not vis by Alice till now
        {
            timeOfVisByAlice[neighbour]=timeOfVisByAlice[node]+1;
            dfs(neighbour,pointsTillCurNode,amount,timeOfVisByAlice,timeOfVisByBob,adj,maxi);
            isLeaf=false;
        }
    }

    if(isLeaf)
    maxi=max(maxi,pointsTillCurNode);
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
        dfs(0,0,amount,timeOfVisByAlice,timeOfVisByBob,adj,maxi);

        return maxi;
    }
};