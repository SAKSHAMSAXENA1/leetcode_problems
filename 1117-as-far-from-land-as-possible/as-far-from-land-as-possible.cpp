class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }

        if(q.size()==0 || q.size()==n*n) // no land cell or no water cell
        return -1;

        int maxDist=0;
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        while(!q.empty())
        {
            int i=q.front().first,j=q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int ni=i+di[k],nj=j+dj[k];

                if(0<=ni && ni<n && 0<=nj && nj<n && grid[ni][nj]==0)
                {
                    if(dist[i][j]+1<dist[ni][nj])
                    {
                        dist[ni][nj]=dist[i][j]+1;
                        maxDist=max(maxDist,dist[ni][nj]);
                        q.push({ni,nj});
                    }
                }
            }
        }

        return maxDist;
    }
};