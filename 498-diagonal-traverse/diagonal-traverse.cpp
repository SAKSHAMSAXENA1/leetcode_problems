class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int di[2]={0,1},dj[2]={1,0};
        vector<int> res(m*n);
        queue<pair<int,int>> q;
        vector<bool> vis(m*n,false);
        q.push({0,0});
        vis[0]=true;
        int idx=0;
        bool diagonal=false;

        while(!q.empty())
        {
            int levelSize=q.size();

            for(int it=0;it<levelSize;it++)
            {
                auto [i,j] = q.front();
                q.pop();

                if(diagonal == false)
                    res[idx+levelSize-it-1]=mat[i][j];
                else
                    res[idx+it]=mat[i][j];
                
                for(int k=0;k<2;k++)
                {
                    int ni=i+di[k],nj=j+dj[k];
                    int newIndex=ni*n+nj;

                    if(0<=ni && ni<m && 0<=nj && nj<n && !vis[newIndex])
                    {
                        vis[newIndex]=true;
                        q.push({ni,nj});
                    }
                }
            }

            idx+=levelSize;
            diagonal=!diagonal;
        }

        return res;
    }
};