class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(auto it:edges)
        {
            int u=it[0],v=it[1],edgeWt=it[2];
            dist[u][v]=dist[v][u]=edgeWt;
        }

        for(int i=0;i<n;i++) dist[i][i]=0;

        for(int via=0;via<n;via++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
            }
        }
        int minNeighbours=n,res=-1;
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(auto it:dist[i])
            {
                if(it<=distanceThreshold) cnt++;
            }

            if(cnt<=minNeighbours)
            {
                minNeighbours=cnt;
                res=i;
            }
        }

        return res;
    }
};