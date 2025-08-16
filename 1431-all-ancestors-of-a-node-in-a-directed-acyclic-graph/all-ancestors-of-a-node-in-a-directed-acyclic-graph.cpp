class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n,vector<int>()),res(n,vector<int>());
        vector<int> indegree(n,0);
        vector<set<int>> ancestors(n,set<int>());
        queue<int> q;

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }

        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        while(!q.empty())
        {
            int cur=q.front();
            q.pop();

            for(auto it:ancestors[cur])
            res[cur].push_back(it);

            for(auto neighbour:adj[cur])
            {
                indegree[neighbour]--;
                ancestors[neighbour].insert(res[cur].begin(),res[cur].end());
                ancestors[neighbour].insert(cur);

                if(indegree[neighbour]==0)
                q.push(neighbour);
            }
        }

        return res;
    }
};