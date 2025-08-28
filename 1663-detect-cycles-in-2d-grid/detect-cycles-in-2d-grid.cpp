class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
bool f(int i,int j,int parentI,int parentJ,vector<vector<char>> &grid,vector<vector<bool>> &vis,
int &m,int &n)
{
    vis[i][j]=true;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        if(0<=ni && ni<m && 0<=nj && nj<n && grid[i][j]==grid[ni][nj])
        {
            if(!vis[ni][nj])
            {
                if(f(ni,nj,i,j,grid,vis,m,n)) return true;
            }
            else if(!(ni==parentI && nj==parentJ)) return true;
        }
    }

    return false;
}
    bool containsCycle(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j])
                {
                    if(f(i,j,-1,-1,grid,vis,m,n)) return true;
                }
            }
        }

        return false;
    }
};