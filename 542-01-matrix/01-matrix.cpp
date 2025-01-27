class Solution {
public:
void bfs(queue<pair<pair<int,int>,int>> &q,int &m,int &n,vector<vector<int>> &mat,
vector<vector<int>> &res)
{
    int di[]={-1,0,1,0},dj[]={0,1,0,-1};
    while(!q.empty())
    {
        int curi=q.front().first.first,curj=q.front().first.second,dist=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
            int ni=curi+di[k],nj=curj+dj[k];

            if(0<=ni && ni<m && 0<=nj && nj<n && res[ni][nj]==INT_MAX)
            {
                res[ni][nj]=dist+1;
                q.push({{ni,nj},dist+1});
            }
        }
    }
}
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));

        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    res[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        bfs(q,m,n,mat,res);

        return res;
    }
};