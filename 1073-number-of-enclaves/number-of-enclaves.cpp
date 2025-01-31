class Solution {
public:
void dfs(int i,int j,int &m,int &n,vector<vector<int>> &grid, vector<vector<bool>> &vis,
int di[],int dj[])
{
    vis[i][j]=true;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if(0<=ni && ni<m && 0<=nj && nj<n && grid[ni][nj]==1 && !vis[ni][nj])
        {
            dfs(ni,nj,m,n,grid,vis,di,dj);
        }
    }
}
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        for(int j=0;j<n;j++)
        {
            if(grid[0][j]==1 && !vis[0][j]) dfs(0,j,m,n,grid,vis,di,dj);

            if(grid[m-1][j]==1 && !vis[m-1][j]) dfs(m-1,j,m,n,grid,vis,di,dj);
        }

        for(int i=0;i<m;i++)
        {
            if(grid[i][0]==1 && !vis[i][0]) dfs(i,0,m,n,grid,vis,di,dj);

            if(grid[i][n-1]==1 && !vis[i][n-1]) dfs(i,n-1,m,n,grid,vis,di,dj);
        }

        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(grid[i][j]==1 && !vis[i][j]) cnt++;
            }
        }

        return cnt;
    }
};