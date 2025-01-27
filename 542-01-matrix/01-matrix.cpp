class Solution {
public:
void bfs(queue<pair<pair<int,int>,int>> &q,int &m,int &n,vector<vector<int>> &mat,
vector<vector<int>> &res,vector<vector<bool>> &vis)
{
    int di[]={-1,0,1,0},dj[]={0,1,0,-1};
    while(!q.empty())
    {
        int curi=q.front().first.first,curj=q.front().first.second,dist=q.front().second;
        q.pop();

        if(mat[curi][curj]==1)
        {
            res[curi][curj]=dist;
        }

        for(int k=0;k<4;k++)
        {
            int ni=curi+di[k],nj=curj+dj[k];

            if(0<=ni && ni<m && 0<=nj && nj<n && !vis[ni][nj])
            {
                vis[ni][nj]=true;
                q.push({{ni,nj},dist+1});
            }
        }
    }
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> res(m,vector<int>(n,0));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }

        bfs(q,m,n,mat,res,vis);

        return res;
    }
};