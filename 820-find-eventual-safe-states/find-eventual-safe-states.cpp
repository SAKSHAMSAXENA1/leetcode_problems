class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> indegree(n,0),safeNodes;
        vector<vector<int>> adjReversed(n,vector<int>());

        for(int u=0;u<n;u++)
        {
            for(auto v: graph[u])
            {
                adjReversed[v].push_back(u);
                indegree[u]++;
            }
        }

        queue<int> q;
        for(int node=0;node<n;node++)
        {
            if(indegree[node]==0) q.push(node);
        }

        while(!q.empty())
        {
            int curNode=q.front();
            q.pop();
            safeNodes.push_back(curNode);

            for(auto neighbour:adjReversed[curNode])
            {
                indegree[neighbour]--;
                if(indegree[neighbour]==0) q.push(neighbour);
            }
        }

        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};