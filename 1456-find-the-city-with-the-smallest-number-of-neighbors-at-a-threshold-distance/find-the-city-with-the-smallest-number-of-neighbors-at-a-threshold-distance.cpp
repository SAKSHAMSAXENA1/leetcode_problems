class Solution {
public:
int f(int &src,vector<vector<pair<int,int>>> &adj, int &distanceThreshold,int &n)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
    vector<int> dist(n,1e9);
    pq.push({0,src}); // {dist,node}
    dist[src]=0;
    
    while(!pq.empty())
    {
        int curDist=pq.top().first,curNode=pq.top().second;
        pq.pop();

        for(auto it:adj[curNode])
        {
            int neighbour=it.first,edgeWt=it.second;
            if(curDist+edgeWt<dist[neighbour])
            {
                dist[neighbour]=curDist+edgeWt;
                pq.push({dist[neighbour],neighbour});
            }
        }
    }
    int cnt=0;
    for(auto it:dist)
    {
        if(it<=distanceThreshold) cnt++;
    }

    return cnt;
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());

        for(auto it:edges)
        {
            int u=it[0],v=it[1],wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        int minNeighbours=n,res=-1;
        for(int i=0;i<n;i++)
        {
            int temp=f(i,adj,distanceThreshold,n);
            if(temp<=minNeighbours) 
            {
                res=i;
                minNeighbours=temp;
            }
        }

        return res;
    }
};