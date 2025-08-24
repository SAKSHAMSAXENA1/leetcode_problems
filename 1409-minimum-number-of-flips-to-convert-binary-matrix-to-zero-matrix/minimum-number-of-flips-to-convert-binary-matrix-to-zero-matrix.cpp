class Solution {
public:
int di[4]={-1,0,1,0},dj[4]={0,1,0,-1};
void flip(vector<vector<int>> &cur,int &i,int &j,int &m,int &n)
{
    cur[i][j]=!cur[i][j];

    for(int k=0;k<4;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        if(0<=ni && ni<m && 0<=nj && nj<n)
        cur[ni][nj]=!cur[ni][nj];
    }
}

bool isZeroMat(vector<vector<int>> &mat)
{
    for(auto row:mat)
    {
        for(auto cell:row)
        if(cell) return false;
    }

    return true;
}
    
    int minFlips(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        set<vector<vector<int>>> vis;
        queue<vector<vector<int>>> q;
        q.push(mat);
        vis.insert(mat);
        int curLevel=0;

        while(!q.empty())
        {
            int levelSize=q.size();

            while(levelSize--)
            {
                auto cur=q.front();
                q.pop();

                if(isZeroMat(cur)) return curLevel;

                // visit all unvisited next states
                for(int i=0;i<m;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        flip(cur,i,j,m,n); // do

                        if(vis.find(cur)==vis.end()) // explore
                        {
                            vis.insert(cur);
                            q.push(cur);
                        }

                        flip(cur,i,j,m,n); // undo
                    }
                }  
            }

            curLevel++;
        }

        return -1;
    }
};