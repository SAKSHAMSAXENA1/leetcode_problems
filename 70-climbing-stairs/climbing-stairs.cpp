class Solution {
public:
int f(int i,vector<int> &dp)
{
    if(i<=2) return i;

    if(dp[i]!=-1) return dp[i];

    return dp[i] =  f(i-1,dp) + f(i-2,dp);
}
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);

        for(int i = 0;i <=min(2,n);i++)
        dp[i]=i;

        for(int i=3;i<=n;i++)
        {
            dp[i] =  dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};