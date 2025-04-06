class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
void dfs(int i,int j,vector<vector<bool>> &vis,vector<vector<int>> &grid,
queue<pair<int,int>> &q,int &n)
{
    vis[i][j]=true;
    q.push({i,j});

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        // if adj cell is unvisited 1, visit it using dfs
        if(0<=ni && ni<n && 0<=nj && nj<n && grid[ni][nj]==1 && !vis[ni][nj])
        {
            dfs(ni,nj,vis,grid,q,n);
        }
    }
}
    int shortestBridge(vector<vector<int>>& grid) {
        int n=grid.size(),level=-1;
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        queue<pair<int,int>> q;
        bool found=false;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    dfs(i,j,vis,grid,q,n);

                    found=true; // island 1 is found, so break out of both the for loops
                    break;
                }
            }
            if(found) break;
        }

        // multi-source bfs from various cells of island 1
        while(!q.empty())
        {
            level++; // cells of island 1 -> at level 0, and so on

            int m=q.size(); // level wise traversal using bfs

            for(int i=0;i<m;i++)
            {
                int curi=q.front().first,curj=q.front().second;
                q.pop();

                for(int k=0;k<4;k++)
                {
                    int ni=curi+di[k],nj=curj+dj[k];

                    if(0<=ni && ni<n && 0<=nj && nj<n && !vis[ni][nj])
                    {
                        if(grid[ni][nj]==1)
                        {
                            return level;
                        }
                        else //if(grid[ni][nj]==0)
                        {
                            q.push({ni,nj});
                            vis[ni][nj]=true;
                        }
                    }
                }
            } 
        }

    return -1;
    }
};