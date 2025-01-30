class Solution {
public:
void dfs(int i,int j,int &m,int &n,vector<vector<char>>& board,vector<vector<bool>> &vis,int di[],int dj[])
{
    vis[i][j]=true;

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        // if the adjacent cell is an unvisited 'O', visit it using dfs
        if(0<=ni && ni<m && 0<=nj && nj<n && board[ni][nj]=='O' && !vis[ni][nj])
        {
            dfs(ni,nj,m,n,board,vis,di,dj);
        }
    }
}
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n, false));
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        for(int j=0;j<n;j++)
        {
            if(board[0][j]=='O' && !vis[0][j]) dfs(0,j,m,n,board,vis,di,dj);

            if(board[m-1][j]=='O' && !vis[m-1][j]) dfs(m-1,j,m,n,board,vis,di,dj);
        }

        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,m,n,board,vis,di,dj);

            if(board[i][n-1]=='O' && !vis[i][n-1]) dfs(i,n-1,m,n,board,vis,di,dj);
        }

        for(int i=1;i<m-1;i++)
        {
            for(int j=1;j<n-1;j++)
            {
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};