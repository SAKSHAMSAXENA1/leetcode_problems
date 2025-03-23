#define mod (int)(1e9+7)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>> pq;
        vector<vector<vector<int>>> adj(n,vector<vector<int>>());
        for(auto edge:roads)
        {
            int u=edge[0],v=edge[1],wt=edge[2];
            adj[u].push_back({v,wt}); // {adjacent node, wt}
            adj[v].push_back({u,wt});
        }
        vector<long> dist(n,LONG_MAX); // all nodes unreachable, initially
        vector<int> cnt(n,1); // only 1 way to reach each node, initially
        dist[0]=0; // dist[src]=0
        pq.push({0,0}); // {dist,node}

        while(!pq.empty())
        {
            int curNode=pq.top().second;
            long curDist=pq.top().first;
            pq.pop();

            for(auto it:adj[curNode])
            {
                int neighbour=it[0],wt=it[1];
                if(curDist+(long)wt<dist[neighbour])
                {
                    dist[neighbour]=curDist+wt;
                    cnt[neighbour]=cnt[curNode]; 
                    // ways to reach neighbour with min dist=ways to reach curNode (adopt)

                    pq.push({dist[neighbour],neighbour});
                }
                else if(curDist+wt==dist[neighbour])
                {
                    cnt[neighbour]=(cnt[neighbour]%mod+cnt[curNode]%mod)%mod;
                    // ways to reach neighbour with min dist + =ways to reach curNode (add)
                }
            }
        }

        return cnt[n-1];
    }
};