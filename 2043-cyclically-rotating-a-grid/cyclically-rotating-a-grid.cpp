class Solution {
public:
void f(int t,int b,int l,int r,vector<vector<int>> &grid,int &k)
{
    int layerSize=2*(b-t+r-l);
    int kEffective = k%layerSize;

    if(kEffective==0) return;

    vector<int> temp;

    for(int i=t;i<=b;i++)
    temp.push_back(grid[i][l]);

    for(int j=l+1;j<=r;j++)
    temp.push_back(grid[b][j]);

    for(int i=b-1;i>=t;i--)
    temp.push_back(grid[i][r]);

    for(int j=r-1;j>l;j--)
    temp.push_back(grid[t][j]);

    int ptr = layerSize - kEffective;

    for(int i=t;i<=b;i++)
    {
        grid[i][l] = temp[ptr];
        ptr = (ptr+1)%layerSize;
    }

    for(int j=l+1;j<=r;j++)
    {
        grid[b][j] = temp[ptr];
        ptr = (ptr+1)%layerSize;
    }

    for(int i=b-1;i>=t;i--)
    {
        grid[i][r] = temp[ptr];
        ptr = (ptr+1)%layerSize;
    }

    for(int j=r-1;j>l;j--)
    {
        grid[t][j] = temp[ptr];
        ptr = (ptr+1)%layerSize;
    }
}
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        int t=0,b=m-1,l=0,r=n-1;

        while(t<b && l<r)
        {
            f(t,b,l,r,grid,k);

            t++;
            b--;
            l++;
            r--;
        }

        return grid;
    }
};