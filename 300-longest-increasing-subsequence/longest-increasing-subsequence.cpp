class Solution {
public:
int f(int i,int last,vector<int> &nums,int &n,vector<vector<int>> &dp)
{
    if(i==0) return 0;

    if(dp[i][last]!=-1) return dp[i][last];

    int take=0,notTake=0;
    if(last==n+1 || nums[i-1]<nums[last-1])
    {
        take=1+f(i-1,i,nums,n,dp);
    }
    
    notTake=f(i-1,last,nums,n,dp);
    
    return dp[i][last]=max(take,notTake);
}
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+2,vector<int> (n+2, 0));

        for(int i=1;i<=n;i++)
        {
            for(int last=1;last<=n+1;last++)
            {
                int take=0,notTake=0;
                if(last==n+1 || nums[i-1]<nums[last-1])
                {
                    take=1+dp[i-1][i];
                }
    
                notTake=dp[i-1][last];
    
                dp[i][last]=max(take,notTake);
            }
        }
        return dp[n][n+1];
    }
};