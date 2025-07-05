class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
bool dfs(int i,int j,vector<vector<int>> &g1,vector<vector<int>> &g2,int &m,int &n,
vector<vector<bool>> &vis)
{
    vis[i][j]=true;

    bool res=true;
    if(g1[i][j]==0) res=false;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        if(0<=ni && ni<m && 0<=nj && nj<n && g2[ni][nj] && !vis[ni][nj])
        {
            res=res & dfs(ni,nj,g1,g2,m,n,vis);
        }
    }

    return res;
}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt=0,m=grid1.size(),n=grid1[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid2[i][j] && !vis[i][j])
                cnt+=dfs(i,j,grid1,grid2,m,n,vis);
            }
        }

        return cnt;
    }
};