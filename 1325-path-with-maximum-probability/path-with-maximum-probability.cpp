class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n,vector<pair<int,double>>());

        int m=edges.size();
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }

        priority_queue<pair<double,int>> pq;
        vector<double> dist(n,0);
        pq.push({1.0,start_node});
        dist[start_node]=1.0;

        while(!pq.empty())
        {
            auto [curDist,node]=pq.top();
            pq.pop();

            if(curDist < dist[node]) // optimization to bypass redundant processing
            continue;

            for(auto it:adj[node])
            {
                auto [neighbour,wt]=it;
                double newDistToNeighbour=curDist * wt;
                
                if(newDistToNeighbour > dist[neighbour])
                {
                    dist[neighbour]=newDistToNeighbour;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }

        return dist[end_node];
    }
};