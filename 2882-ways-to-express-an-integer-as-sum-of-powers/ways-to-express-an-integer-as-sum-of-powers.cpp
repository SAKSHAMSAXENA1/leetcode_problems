#define ll long long
#define mod (ll)(1e9+7)
class Solution {
public:
int findLargestNk(int &n,int &x)
{
    int l=1,h=n,res=n;

    while(l<=h)
    {
        int mid=(l+h)/2;

        if(pow(mid,x) <= n)
        {
            res=mid;
            l=mid+1;
        }
        else h=mid-1;
    }

    return res;
}

ll f(int i,int n,int &x,int &largestNk,vector<vector<ll>> &dp)
{
    if(n==0) return 1;

    if(i>largestNk) return 0;

    if(dp[i][n]!=-1) return dp[i][n];

    ll take=0;
    if(pow(i,x) <= n)
    take=f(i+1,n-pow(i,x),x,largestNk,dp)%mod;

    ll notTake=f(i+1,n,x,largestNk,dp)%mod;

    return dp[i][n]=(take+notTake)%mod;
}
    int numberOfWays(int n, int x) {
        int largestNk=findLargestNk(n,x);
        vector<vector<ll>> dp(largestNk+1,vector<ll>(n+1,-1));
        return f(1,n,x,largestNk,dp);
    }
};