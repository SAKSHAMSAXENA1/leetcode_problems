class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor=image[sr][sc];
        if(originalColor==color) return image;
        int m=image.size(),n=image[0].size();
        //vector<vector<bool>> vis(m,vector<bool>(n,false));
        int di[]={-1,0,1,0},dj[]={0,1,0,-1};

        queue<pair<int,int>> q;
        //vis[sr][sc]=true;
        image[sr][sc]=color;
        q.push({sr,sc});

        while(!q.empty())
        {
            int curi=q.front().first,curj=q.front().second;
            q.pop();

            for(int k=0;k<4;k++)
            {
                int ni=curi+di[k],nj=curj+dj[k];

                if(0<=ni && ni<m && 0<=nj && nj<n && image[ni][nj]==originalColor)
                {
                    image[ni][nj]=color;
                    q.push({ni,nj});
                }
            }
        }

        return image;
    }
};