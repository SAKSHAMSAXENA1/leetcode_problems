#define ll long long
class Solution {
public:
/*
// Memoization
ll f(int i,int prevParity,vector<int> &nums,int &x,int &n,vector<vector<ll>> &dp)
{
    if(i==n) return 0;

    if(dp[i][prevParity]!=-1) return dp[i][prevParity];

    int curParity=nums[i]%2;
    ll take=(ll)nums[i]-(i>0 && curParity!=prevParity)*x+f(i+1,nums[i]%2,nums,x,n,dp);

    ll notTake=LLONG_MIN;

    if(i>0)
    notTake=f(i+1,prevParity,nums,x,n,dp);

    return dp[i][prevParity]=max(take,notTake);
}
    long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return f(0,0,nums,x,n,dp);
    }
};*/

// Tabulation
long long maxScore(vector<int>& nums, int x) {
        int n=nums.size();
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int prevParity=1;prevParity>=0;prevParity--)
            {
                int curParity=nums[i]%2;
                ll take=(ll)nums[i]-(i>0 && curParity!=prevParity)*x+dp[i+1][curParity];

                ll notTake=LLONG_MIN;

                if(i>0)
                notTake=dp[i+1][prevParity];

                dp[i][prevParity]=max(take,notTake);
            }
        }
        return dp[0][0];
    }
};