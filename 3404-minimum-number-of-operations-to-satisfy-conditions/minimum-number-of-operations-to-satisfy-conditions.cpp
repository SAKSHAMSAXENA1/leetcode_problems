class Solution {
public:
int f(int col,int prevDig,vector<vector<int>> &grid,vector<vector<int>> &freq,int &m,int &n,
vector<vector<int>> &dp)
{
    if(col==n) return 0; // base case

    if(dp[col][prevDig]!=-1) return dp[col][prevDig];

    int mini = INT_MAX;
    for(int take = 0;take<=9;take++)
    {
        if(take==prevDig) continue;

        int curCost = m - freq[col][take];

        mini=min(mini,curCost + f(col+1,take,grid,freq,m,n,dp));
    }

    return dp[col][prevDig] = mini;
}
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        vector<vector<int>> freq(n,vector<int>(10,0));
        vector<int> cur(11,0),prev(11,0);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                freq[j][grid[i][j]]++;
            }
        }

        for(int col=n-1;col>=0;col--)
        {
            for(int prevDig=0;prevDig<=10;prevDig++)
            {
                int mini = INT_MAX;
                for(int take = 0;take<=9;take++)
                {
                    if(take==prevDig) continue;

                    int curCost = m - freq[col][take];

                    mini=min(mini,curCost + prev[take]);
                }

                cur[prevDig] = mini;
            }

            prev = cur;
        }

        return prev[10];
    }
};