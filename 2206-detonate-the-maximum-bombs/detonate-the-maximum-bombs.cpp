class Solution {
public:
void dfs(int node,vector<vector<int>> &adj,vector<bool> &vis,int &cnt)
{
    vis[node]=true;
    cnt++;

    for(auto neighbour : adj[node])
    {
        if(!vis[neighbour])
        {
            dfs(neighbour,adj,vis,cnt);
        }
    }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size(),maxi=0;
        vector<vector<int>> adj(n,vector<int>());

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                long distSq=pow(bombs[i][0]-bombs[j][0],2)+pow(bombs[i][1]-bombs[j][1],2);
                long radSq=pow(bombs[i][2],2);

                if(distSq <= radSq) // bomb 'i' can detonate bomb 'j'
                adj[i].push_back(j);
            }
        }

        for(int i=0;i<n;i++)
        {
            vector<bool> vis(n,false);
            int cnt=0;
            dfs(i,adj,vis,cnt);
            maxi=max(maxi,cnt);
        }

        return maxi;
    }
};