class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
bool dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &m,int &n)
{
    vis[i][j]=true;

    bool res=true;
    if(i==0 || i==m-1 || j==0 || j==n-1) res=false;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        if(0<=ni && ni<m && 0<=nj && nj<n && !grid[ni][nj] && !vis[ni][nj])
        {
            res=res & dfs(ni,nj,grid,vis,m,n);
        }
    }

    return res;
}
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cnt+=(!grid[i][j] && !vis[i][j] && dfs(i,j,grid,vis,m,n));
            }
        }

        return cnt;
    }
};