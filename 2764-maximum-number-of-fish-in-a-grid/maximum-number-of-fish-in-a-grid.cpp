class Solution {
public:
int dfs(int i,int j,int &m,int &n,vector<vector<int>>& grid,vector<vector<bool>> &vis,
int di[],int dj[])
{
    vis[i][j]=true;

    int res=grid[i][j];

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        // adjacent cell is unvisited water cell
        if(0<=ni && ni<m && 0<=nj && nj<n && grid[ni][nj]>0 && !vis[ni][nj])
        {
            res+=dfs(ni,nj,m,n,grid,vis,di,dj);
        }
    }

    return res;
}
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),maxi=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]>0 && !vis[i][j])
                {
                    maxi=max(maxi,dfs(i,j,m,n,grid,vis,di,dj));
                }
            }
        }

        return maxi;
    }
};