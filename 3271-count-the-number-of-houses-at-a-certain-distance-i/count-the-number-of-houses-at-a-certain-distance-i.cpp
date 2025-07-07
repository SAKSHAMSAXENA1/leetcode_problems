class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int>res(n,0);
        vector<vector<int>> adj(n+1,vector<int>());
        vector<vector<int>> dist(n+1,vector<int>(n+1,INT_MAX));

        for(int i=1;i<=n;i++)
        {
            dist[i][i]=0;
            if(i+1<=n)
            {
                adj[i].push_back(i+1);
                dist[i][i+1]=1;
            }
            if(i-1>=1)
            {
                adj[i].push_back(i-1);
                dist[i][i-1]=1;
            }
        }

        adj[x].push_back(y);
        dist[x][y]=(x!=y);
        adj[y].push_back(x);
        dist[y][x]=(x!=y);

        for(int intermediate=1;intermediate<=n;intermediate++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    if(dist[i][intermediate]==INT_MAX || dist[intermediate][j]==INT_MAX)
                    continue;

                    if(dist[i][intermediate]+dist[intermediate][j]<dist[i][j])
                    dist[i][j]=dist[i][intermediate]+dist[intermediate][j];
                }
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            if(i!=j) 
            res[dist[i][j]-1]++;
        }

        return res;
    }
};