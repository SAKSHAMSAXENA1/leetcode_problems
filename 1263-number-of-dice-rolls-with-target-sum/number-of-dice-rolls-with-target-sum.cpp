#define mod (int)(1e9+7)
class Solution {
public:
int f(int index,int rem,int &n,int &k,vector<vector<int>> &dp)
{
    if(index==n) return rem==0;

    if(n-index>rem) return 0;

    if(dp[index][rem]!=-1) return dp[index][rem];

    int noOfWays=0;

    for(int faceVal=1;faceVal<=k && faceVal<=rem;faceVal++)
    {
        noOfWays=(noOfWays+f(index+1,rem-faceVal,n,k,dp))%mod;
    }

    return dp[index][rem]=noOfWays;
}
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return f(0,target,n,k,dp);
    }
};