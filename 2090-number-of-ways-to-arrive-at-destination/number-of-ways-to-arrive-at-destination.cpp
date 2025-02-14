class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto it:roads)
        {
            int u=it[0],v=it[1],edgeWt=it[2];
            adj[u].push_back({v,edgeWt});
            adj[v].push_back({u,edgeWt});
        }
        vector<long long> dist(n,1e18),noOfWays(n,0);
        int mod=1e9+7;
        dist[0]=0;
        noOfWays[0]=1;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        pq.push({0,0}); 

        while(!pq.empty())
        {
            long long curDist=pq.top().first;
            int curNode=pq.top().second;
            pq.pop();

            for(auto edge:adj[curNode])
            {
                int neighbour=edge.first,edgeWeight=edge.second;

                if(curDist+edgeWeight<dist[neighbour])
                {
                    dist[neighbour]=curDist+edgeWeight;
                    noOfWays[neighbour]=noOfWays[curNode];

                    if(neighbour!=n-1) pq.push({dist[neighbour],neighbour});
                }
                else if(curDist+edgeWeight==dist[neighbour])
                {
                    noOfWays[neighbour]=(noOfWays[neighbour]+noOfWays[curNode])%mod;
                }
            }
        }

        return noOfWays[n-1];
    }
};