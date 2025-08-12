#define ll long long
#define mod (ll)(1e9+7)
class Solution {
public:
int findLargestBase(ll &n,int &x)
{
    ll l=0,h=n,res=0;

    while(l<=h)
    {
        ll mid=(l+h)/2;

        if(pow(mid,x) <= n)
        {
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }

    return res;
}

/* 
// Memoition
ll f(int i,ll rem,int &x,ll &largestBase,vector<vector<ll>> &dp)
{
    if(rem==0) return 1;

    if(i>largestBase) return 0;

    if(dp[i][rem]!=-1) return dp[i][rem];

    ll cur=pow(i,x);

    ll take=0;
    if(cur <= rem)
    take=f(i+1,rem-cur,x,largestBase,dp);

    ll notTake=f(i+1,rem,x,largestBase,dp);

    return dp[i][rem]=(take+notTake)%mod;
}
    int numberOfWays(int n, int x) {
        ll N=n;
        ll largestBase=findLargestBase(N,x);
        vector<vector<ll>> dp(largestBase+1,vector<ll>(n+1,-1));
        return f(1,n,x,largestBase,dp);
    }
*/

// Tabulation
    int numberOfWays(int n, int x) {
        ll N=n;
        ll largestBase=findLargestBase(N,x);
        vector<vector<ll>> dp(largestBase+2,vector<ll>(n+1,0));

        for(int i=0;i<=largestBase+1;i++) dp[i][0]=1; // for rem=0, value=1

        for(int i=largestBase;i>=1;i--)
        {
            for(int rem=1;rem<=n;rem++)
            {
                ll cur=pow(i,x);

                ll take=0;
                if(cur <= rem)
                take=dp[i+1][rem-cur];

                ll notTake=dp[i+1][rem];

                dp[i][rem]=(take+notTake)%mod;
            }
        } 

        return dp[1][n];
    }
};