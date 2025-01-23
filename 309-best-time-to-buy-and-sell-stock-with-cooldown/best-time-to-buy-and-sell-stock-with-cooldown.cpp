class Solution {
public:
int f(int i,int buy,vector<int> &prices, int &n,vector<vector<int>> &dp)
{
    if(i>=n) return 0;

    if(dp[i][buy]!=-1) return dp[i][buy];

    int profit=0;
    if(buy)
    {
        profit=max(-prices[i]+f(i+1,0,prices,n,dp),0+f(i+1,1,prices,n,dp));
    }
    else // not allowed to buy
    {
        profit=max(prices[i]+f(i+2,1,prices,n,dp),0+f(i+1,0,prices,n,dp));
    }

    return dp[i][buy]=profit;
}
    int maxProfit2(vector<int>& prices) {
        int n=prices.size();
        
        vector<int> ahead(2,0),cur(2,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    profit=max(-prices[i]+ahead[0],ahead[1]);
                }
                else // not allowed to buy
                {
                    profit=max(prices[i]+ahead[1],ahead[0]);
                }

                cur[buy]=profit;
            }
            ahead=cur;
        }

        return ahead[1];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,-1));
        return f(0,1,prices,n,dp);
    }
};