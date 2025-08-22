class Solution {
public:
vector<int> postOrder(int node,vector<vector<int>> &adj,vector<bool> &vis,vector<int> &res,
string &labels)
{
    vis[node]=true;
    vector<int> freq(26,0);

    for(auto neighbour:adj[node])
    {
        if(!vis[neighbour])
        {
            vector<int> freqNeighbour=postOrder(neighbour,adj,vis,res,labels);

            for(int i=0;i<26;i++)
            freq[i]+=freqNeighbour[i];
        }
    }

    // all children of cur node have been visited now
    freq[labels[node]-'a']++;
    res[node]=freq[labels[node]-'a'];
    return freq;
}
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n);
        vector<bool> vis(n,false);
        vector<vector<int>> adj(n,vector<int>());

        for(auto it:edges)
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        postOrder(0,adj,vis,res,labels);
        return res;
    }
};