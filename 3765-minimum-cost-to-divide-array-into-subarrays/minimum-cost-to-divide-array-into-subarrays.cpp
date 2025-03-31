#define ll long long
class Solution {
public:
ll f(int r,vector<int> &prefixNums,vector<int> &prefixCost,vector<ll> &dp,int &k,int &n)
{
    if(r==0) return 0;

    if(dp[r]!=-1) return dp[r];

    ll mini=LLONG_MAX;
    for(int l=r;l>=1;l--)
    {
        ll curCost=(ll)prefixNums[r-1]*(prefixCost[r-1]-((l>1)?prefixCost[l-1-1]:0))
        +(ll)k*(prefixCost[n-1]-((l>1)?prefixCost[l-1-1]:0));
        ll prevPartition=f(l-1,prefixNums,prefixCost,dp,k,n);
        mini=min(mini,curCost+prevPartition);
    }

    return dp[r]=mini;
}
    long long minimumCost(vector<int>& nums, vector<int>& cost, int k) {
        int n=nums.size();
        vector<int> prefixNums(n),prefixCost(n);
        prefixNums[0]=nums[0];
        prefixCost[0]=cost[0];

        for(int i=1;i<n;i++)
        {
            prefixNums[i]=prefixNums[i-1]+nums[i];
            prefixCost[i]=prefixCost[i-1]+cost[i];
        }

        vector<ll> dp(n+1,-1);
        dp[0]=0; // base case

        for(int r=1;r<=n;r++)
        {
            ll mini=LLONG_MAX;
            for(int l=r;l>=1;l--)
            {
                ll curCost=(ll)prefixNums[r-1]*(prefixCost[r-1]-((l>1)?prefixCost[l-1-1]:0))
                +(ll)k*(prefixCost[n-1]-((l>1)?prefixCost[l-1-1]:0));
                ll prevPartition=dp[l-1];
                mini=min(mini,curCost+prevPartition);
            }

            dp[r]=mini;
        }

        return dp[n];
    }
};