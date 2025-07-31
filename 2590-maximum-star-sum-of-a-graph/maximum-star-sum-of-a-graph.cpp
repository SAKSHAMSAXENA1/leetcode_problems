class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size(),maxi=INT_MIN;
        vector<priority_queue<int>> adj(n,priority_queue<int>());

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push(vals[v]);
            adj[v].push(vals[u]);
        }

        for(int node=0;node<n;node++)
        {
            int cnt=k,sum=vals[node];

            while(cnt-- && !adj[node].empty() && adj[node].top()>0)
            {
                sum+=adj[node].top();
                adj[node].pop();
            }

            maxi=max(maxi,sum);
        }

        return maxi;
    }
};