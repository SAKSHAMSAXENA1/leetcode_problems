class Solution {
public:
void checkInSameRow(int &ik,int &jk,vector<vector<bool>> &grid,vector<vector<int>> &res,int &n)
{
    for(int j=jk-1;j>=0;j--)
        if(grid[ik][j])
        {
            res.push_back({ik,j});
            break;
        }

        for(int j=jk+1;j<n;j++)
        if(grid[ik][j])
        {
            res.push_back({ik,j});
            break;
        }
}

void checkInSameCol(int &ik,int &jk,vector<vector<bool>> &grid,vector<vector<int>> &res,int &n)
{
    for(int i=ik-1;i>=0;i--)
        if(grid[i][jk])
        {
            res.push_back({i,jk});
            break;
        }

        for(int i=ik+1;i<n;i++)
        if(grid[i][jk])
        {
            res.push_back({i,jk});
            break;
        }
}

void checkInSameDiagonal(int &ik,int &jk,vector<vector<bool>> &grid,vector<vector<int>> &res,int &n)
{
    int i=ik+1,j=jk+1;
    while(i<n && j<n)
    {
        if(grid[i][j])
        {
            res.push_back({i,j});
            break;
        }

        i++;j++;
    }

    i=ik-1;j=jk-1;
    while(i>=0 && j>=0)
    {
        if(grid[i][j])
        {
            res.push_back({i,j});
            break;
        }

        i--;j--;
    }

    i=ik+1;j=jk-1;
    while(i<n && j>=0)
    {
        if(grid[i][j])
        {
            res.push_back({i,j});
            break;
        }

        i++;j--;
    }

    i=ik-1;j=jk+1;
    while(i>=0 && j<n)
    {
        if(grid[i][j])
        {
            res.push_back({i,j});
            break;
        }

        i--;j++;
    }
}
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        int n=8;
        vector<vector<bool>> grid(n,vector<bool>(n,false));
        vector<vector<int>> res;

        for(auto it:queens)
        {
            int i=it[0],j=it[1];
            grid[i][j]=true;
        }

        int ik=king[0],jk=king[1];

        checkInSameCol(ik,jk,grid,res,n);
        checkInSameRow(ik,jk,grid,res,n);
        checkInSameDiagonal(ik,jk,grid,res,n);

        return res;
    }
};