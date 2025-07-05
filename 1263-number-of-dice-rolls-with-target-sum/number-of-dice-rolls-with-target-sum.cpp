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
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        dp[n][0]=1;

        for(int index=n-1;index>=0;index--)
        {
            for(int rem=0;rem<=target;rem++)
            {
                if(n-index>rem) continue;

                int noOfWays=0;

                for(int faceVal=1;faceVal<=k && faceVal<=rem;faceVal++)
                {
                    noOfWays=(noOfWays+dp[index+1][rem-faceVal])%mod;
                }

                dp[index][rem]=noOfWays;
            }
        }
        return dp[0][target];
    }
};