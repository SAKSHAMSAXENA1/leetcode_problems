class Solution {
public:

int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>> &vis,int &cnt,int &m,int &n)
{
    vis[i][j]=true;
    cnt++;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if(0<=ni && ni<m && 0<=nj && nj<n && grid[ni][nj] && !vis[ni][nj])
        dfs(ni,nj,grid,vis,cnt,m,n);
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] && !vis[i][j])
                {
                    int cnt=0;
                    dfs(i,j,grid,vis,cnt,m,n);
                    maxi=max(maxi,cnt);
                }
            }
        }

        return maxi;
    }
};