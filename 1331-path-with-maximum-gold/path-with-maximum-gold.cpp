class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
int dfs(int i,int j,vector<vector<int>> &grid,int &m,int &n)
{
    int originalVal=grid[i][j];
    grid[i][j]=0; // vis[i][j]=true;

    int maxi=0;
    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];
        if(0<=ni && ni<m && 0<=nj && nj<n && grid[ni][nj])
        {
            maxi=max(maxi,dfs(ni,nj,grid,m,n));
        }
    }

    grid[i][j]=originalVal; // vis[i][j]=false;

    return maxi+grid[i][j];
}
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),res=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;

                res=max(res,dfs(i,j,grid,m,n));
            }
        }

        return res;
    }
};