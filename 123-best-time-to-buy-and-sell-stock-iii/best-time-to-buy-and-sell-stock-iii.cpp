class Solution {
public:
int f(int i,int remTrx,int buy,vector<int>& prices,int n,vector<vector<vector<int>>> &dp)
{
    if(remTrx==0 || i==n) return 0;

    if(dp[i][remTrx][buy]!=-1) return dp[i][remTrx][buy];

    int profit=0;
    if(buy)
    {
        profit=max(-prices[i]+f(i+1,remTrx,0,prices,n,dp),f(i+1,remTrx,1,prices,n,dp));
    }
    else
    {
        profit=max(prices[i]+f(i+1,remTrx-1,1,prices,n,dp),f(i+1,remTrx,0,prices,n,dp));
    }

    return dp[i][remTrx][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int> (2,-1)));
        return f(0,2,1,prices,n,dp);
    }
};