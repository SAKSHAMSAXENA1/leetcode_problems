class Solution {
public:
void bfs(queue<pair<pair<int,int>,int>> &q,int &m,int &n,vector<vector<int>> &isWater, vector<vector<int>> &res)
{
    int di[]={-1,0,1,0},dj[]={0,1,0,-1};
    while(!q.empty())
    {
        int curi=q.front().first.first,curj=q.front().first.second,height=q.front().second;
        q.pop();

        for(int k=0;k<4;k++)
        {
            int ni=curi+di[k],nj=curj+dj[k];

            //adjacent cell is an unvisited land cell
            if(0<=ni && ni<m && 0<=nj && nj<n && res[ni][nj]==INT_MAX)
            {
                res[ni][nj]=height+1; // this makes the adj land cell visited, since its
                // height is no longer INT_MAX
                q.push({{ni,nj},height+1});
            }
        }
    }
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size(),n=isWater[0].size();
        vector<vector<int>> res(m,vector<int>(n,INT_MAX));//unvisited land cells have INT_MAX
        queue<pair<pair<int,int>,int>> q;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isWater[i][j])
                {
                    res[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }

        bfs(q,m,n,isWater,res);

        return res;
    }
};