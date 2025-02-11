class Solution {
public:
bool isValid(int &i,int &j,int &n,vector<vector<int>>& grid)
{
    return 0<=i && i<n && 0<=j && j<n && grid[i][j]==0;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        vector<vector<int>> dist(n,vector<int> (n, 1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int di[]={-1,-1,-1,0,1,1,1,0},dj[]={-1,0,1,1,1,0,-1,-1};

        while(!pq.empty())
        {
            int curDist=pq.top().first,curi=pq.top().second.first,curj=pq.top().second.second;
            pq.pop();

            for(int k=0;k<8;k++)
            {
                int ni=curi+di[k],nj=curj+dj[k];

                if(isValid(ni,nj,n,grid) && curDist+1<dist[ni][nj])
                {
                    dist[ni][nj]=curDist+1;
                    pq.push({dist[ni][nj],{ni,nj}});
                }
            }
        }

        if(dist[n-1][n-1]==1e9) return -1; // unreachable
        return dist[n-1][n-1]+1;
    }
};