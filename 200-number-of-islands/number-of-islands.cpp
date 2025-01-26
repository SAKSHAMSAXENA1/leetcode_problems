class Solution {
public:
void bfs(int i,int j,vector<vector<char>> &grid, vector<vector<bool>> &vis,int di[],int dj[],
int &m, int &n)
{
    vis[i][j]=true;
    queue<pair<int,int>> q;
    q.push({i,j});

    while(!q.empty())
    {
        int curi=q.front().first,curj=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
            int ni=curi+di[k],nj=curj+dj[k];

            if(0<=ni && ni<m && 0<=nj && nj<n && grid[ni][nj]=='1' && !vis[ni][nj])
            {
                vis[ni][nj]=true;
                q.push({ni,nj});
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    bfs(i,j,grid,vis,di,dj,m,n);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};