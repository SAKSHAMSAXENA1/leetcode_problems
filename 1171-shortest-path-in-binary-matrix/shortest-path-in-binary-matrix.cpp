class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]) return -1;
        
        int n=grid.size();
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        int di[]={-1,-1,0,1,1,1,0,-1},dj[]={0,1,1,1,0,-1,-1,-1};
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=true;
        int curLevel=1;

        while(!q.empty())
        {
            int curLevelElements=q.size();

            while(curLevelElements--)
            {
                int i=q.front().first,j=q.front().second;
                q.pop();
                if(i==n-1 && j==n-1) return curLevel;

                for(int k=0;k<8;k++)
                {
                    int ni=i+di[k],nj=j+dj[k];

                    if(0<=ni && ni<n && 0<=nj && nj<n && !grid[ni][nj] && !vis[ni][nj])
                    {
                        vis[ni][nj]=true;
                        q.push({ni,nj});
                    }
                }
            }

            curLevel++;
        }

        return -1;
    }
};