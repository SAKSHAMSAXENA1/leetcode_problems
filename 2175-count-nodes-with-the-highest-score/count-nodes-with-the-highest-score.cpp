class Solution {
public:
int dfs(int node,vector<vector<int>> &adj,vector<int> &subtreeSz,long &maxScore,int &cnt,int &n)
{
    long prod = 1;
    int sum = 0;
    for(auto &child : adj[node])
    {
        int childSz = dfs(child,adj,subtreeSz,maxScore,cnt,n);
        prod *= childSz;
        sum +=childSz;
    }
    
    subtreeSz[node] = sum + 1;

    long score = (max(n-subtreeSz[node],1)) * prod;

    if(score > maxScore)
    {
        maxScore = score;
        cnt = 1;
    }
    else if(score == maxScore)
    cnt++;

    return subtreeSz[node];
}
    int countHighestScoreNodes(vector<int>& parents) {
        int n=parents.size();
        vector<vector<int>> adj(n,vector<int>());
        vector<int> subtreeSz(n,0);
        long maxScore = INT_MIN;
        int cnt = 0;

        for(int node=1;node<n;node++)
        {
            adj[parents[node]].push_back(node);
        }

        dfs(0,adj,subtreeSz,maxScore,cnt,n);
        
        return cnt;
    }
};