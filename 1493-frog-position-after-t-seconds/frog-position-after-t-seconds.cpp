class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1,vector<int>());
        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> time(n+1,INT_MAX);
        vector<double> prob(n+1,0);
        vector<bool> isLeafVertex(n+1,false);
        queue<int> q;
        q.push(1);
        time[1]=0;
        prob[1]=1;

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            int nextNodes=0;

            for(auto neighbour:adj[cur])
            {
                if(time[cur]+1<time[neighbour])
                nextNodes++;
            }

            isLeafVertex[cur]=(nextNodes==0);

            for(auto neighbour:adj[cur])
            {
                if(time[cur]+1<time[neighbour])
                {
                    time[neighbour]=time[cur]+1;
                    q.push(neighbour);
                    prob[neighbour]=prob[cur] * (1.0/nextNodes);
                }
            }
        }

        if(t<time[target]) return 0; // because target cannot be vis before time[target]
        // else time[target] <= t

        if(isLeafVertex[target])
        return prob[target]; // bec frog stays at leaf vertex for time 't' > time[target]

        // else target is not a leaf vertex
        // so frog is present at target only at time[target]
        // for time 't' > time[target] frog moves to other nodes

        if(t==time[target]) return prob[target];
        // else
        return 0;
    }
};