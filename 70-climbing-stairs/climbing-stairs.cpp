class Solution {
public:
int f(int i,vector<int> &dp)
{
    if(i<=2) return i;

    if(dp[i]!=-1) return dp[i];

    return dp[i] =  f(i-1,dp) + f(i-2,dp);
}
    int climbStairs(int n) {
        if(n<=2) return n;

        int prev1=2,prev2=1,cur=0;

        for(int i=3;i<=n;i++)
        {
            cur =  prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return prev1;
    }
};