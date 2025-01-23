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
        vector<vector<int>> ahead(3, vector<int> (2,0)),cur(3, vector<int> (2,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int remTrx=1;remTrx<=2;remTrx++)
            {
                for(int buy=0;buy<=1;buy++)
                {
                    int profit=0;
                    if(buy)
                    {
                        profit=max(-prices[i]+ahead[remTrx][0],ahead[remTrx][1]);
                    }
                    else
                    {
                        profit=max(prices[i]+ahead[remTrx-1][1],ahead[remTrx][0]);
                    }

                    cur[remTrx][buy]=profit;
                }
            }
            ahead=cur;
        }
        return ahead[2][1];
    }
};