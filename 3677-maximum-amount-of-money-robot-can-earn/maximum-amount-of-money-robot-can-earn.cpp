class Solution {
public:
int di[2]={0,1},dj[2]={1,0};
int f(int i,int j,int remPower,vector<vector<int>> &coins,int &m,int &n,
vector<vector<vector<int>>> &dp,vector<vector<vector<bool>>> &vis)
{
    if(i==m-1 && j==n-1)
    {
        /*if(coins[i][j] >= 0) return coins[i][j];
        else // coins[i][j] < 0
        {
            if(remPower > 0) return 0;
            else return coins[i][j];
        }*/
        if(coins[i][j]>=0 || remPower==0) return coins[i][j];
        else return 0;
    }

    if(vis[i][j][remPower]) return dp[i][j][remPower];

    int usePower=INT_MIN;
    if(coins[i][j] < 0 && remPower > 0) // robber is present
    {
        usePower=0;
        int maxi=INT_MIN;

        for(int k=0;k<2;k++)
        {
            int ni=i+di[k],nj=j+dj[k];

            if(0<=ni && ni<m && 0<=nj && nj<n)
            {
                maxi=max(maxi,f(ni,nj,remPower-1,coins,m,n,dp,vis));
            }
        }

        usePower+=maxi;
    }

    // robber is not present or I don't have power to avoid robber

    int powerNotUsed=coins[i][j];
    int maxi=INT_MIN;

    for(int k=0;k<2;k++)
    {
        int ni=i+di[k],nj=j+dj[k];

        if(0<=ni && ni<m && 0<=nj && nj<n)
        {
            maxi=max(maxi,f(ni,nj,remPower,coins,m,n,dp,vis));
        }
    }

    powerNotUsed+=maxi;

    vis[i][j][remPower]=true;
    return dp[i][j][remPower]=max(usePower,powerNotUsed);
}
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size(),n=coins[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(3)));
        vector<vector<vector<bool>>> vis(m,vector<vector<bool>>(n,vector<bool>(3,false)));
        return f(0,0,2,coins,m,n,dp,vis);
    }
};